#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

#define MAX_PROCESSES 4
#define MAX_CPU_TIME 8
#define MIN_CPU_TIME 5
#define MAX_ARRIVAL_TIME 3
#define DISK_TIME 2
#define TAPE_TIME 3
#define PRINTER_TIME 4
#define MAX_IO_TYPES 3
#define QUANTUM 2

typedef enum {
    DISK,
    TAPE,
    PRINTER
} IOType;

typedef enum {
    READY,
    RUNNING,
    IO
} ProcessStatus;

typedef struct {
    IOType type;
    int duration;
    int start_time;
    int remaining_time;
} IOOperation;

typedef struct {
    int pid;
    int arrival_time;
    int start_time;
    int cpu_time;
    int remaining_cpu_time;
    int quantum_time_remaining;
    int current_cpu_time;
    int conclusion_time;
    int num_io_ops;
    int io_op_index;
    int priority;
    int aux;
    ProcessStatus status;
    IOOperation *io_ops; 
} Process;


typedef struct Node {
    Process process;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = queue->rear = NULL;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, Process process) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->process = process;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Process dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = queue->front;
    Process process = temp->process;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return process;
}

const char *ioTypeToString(IOType type) {
    switch (type) {
        case DISK:
            return "Disk";
        case TAPE:
            return "Tape";
        case PRINTER:
            return "Printer";
        default:
            return "Unknown";
    }
}

Process *initializeProcesses(int num_processes) {
    Process *processes = (Process *)malloc(num_processes * sizeof(Process));
    if (processes == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % (MAX_ARRIVAL_TIME + 1);
        processes[i].cpu_time = rand() % (MAX_CPU_TIME - MIN_CPU_TIME + 1) + MIN_CPU_TIME;
        processes[i].remaining_cpu_time = processes[i].cpu_time;
        processes[i].quantum_time_remaining = 0;
        processes[i].current_cpu_time = 0;
        processes[i].status = READY;
        processes[i].aux = rand() % 20 + 5;
        processes[i].num_io_ops = rand() % MAX_IO_TYPES;
        processes[i].priority = 0;
        if (processes[i].num_io_ops > 0) {
            processes[i].io_op_index = 0;
            processes[i].io_ops = (struct {
                IOType type;
                int duration;
                int start_time;
                int remaining_time;
            } *)malloc(processes[i].num_io_ops * sizeof(struct {
                IOType type;
                int duration;
                int start_time;
                int remaining_time;
            }));
            if (processes[i].io_ops == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            for (int j = 0; j < processes[i].num_io_ops; j++) {
                processes[i].io_ops[j].type = rand() % MAX_IO_TYPES;
                switch (processes[i].io_ops[j].type) {
                    case DISK:
                        processes[i].io_ops[j].duration = DISK_TIME;
                        break;
                    case TAPE:
                        processes[i].io_ops[j].duration = TAPE_TIME;
                        break;
                    case PRINTER:
                        processes[i].io_ops[j].duration = PRINTER_TIME;
                        break;
                }
                processes[i].io_ops[j].start_time = rand() % MAX_IO_TYPES + 1;
                processes[i].io_ops[j].remaining_time = processes[i].io_ops[j].duration;
            }
        } else {
            processes[i].io_ops = NULL;
        }
    }
    return processes;
}

void simulateRoundRobin(Process *processes, int num_processes) {
    Queue highPriorityQueue;
    Queue lowPriorityQueue;
    initializeQueue(&highPriorityQueue);
    initializeQueue(&lowPriorityQueue);
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].status == READY && processes[i].arrival_time == current_time) {
                processes[i].start_time = current_time;
                if (processes[i].priority == 0)
                    enqueue(&highPriorityQueue, processes[i]);
                else
                    enqueue(&lowPriorityQueue, processes[i]);
            }
        }

        Queue *currentQueue = !isQueueEmpty(&highPriorityQueue) ? &highPriorityQueue : &lowPriorityQueue;

        if (!isQueueEmpty(currentQueue)) {
            Process runningProcess = dequeue(currentQueue);
            runningProcess.status = RUNNING;

            int quantum = runningProcess.quantum_time_remaining > 0 ? runningProcess.quantum_time_remaining : QUANTUM;
            runningProcess.quantum_time_remaining = quantum;

            while (runningProcess.remaining_cpu_time > 0 && quantum > 0) {
                printf("Time %d: ", current_time);
                for (int i = 0; i < runningProcess.num_io_ops; i++) {
                    if (runningProcess.io_ops[i].start_time == runningProcess.current_cpu_time) {
                        printf("Process %d is performing IO - Type: %s.\n", runningProcess.pid, ioTypeToString(runningProcess.io_ops[i].type));
                        runningProcess.status = IO;
                        runningProcess.io_ops[i].remaining_time--;
                        if (runningProcess.io_ops[i].remaining_time == 0) {
                            runningProcess.io_op_index++;
                            if (runningProcess.io_op_index < runningProcess.num_io_ops) {
                                runningProcess.io_ops[i].start_time = runningProcess.current_cpu_time + rand() % MAX_IO_TYPES + 1;
                                runningProcess.io_ops[i].remaining_time = runningProcess.io_ops[i].duration;
                            }
                            switch (runningProcess.io_ops[i].type) {
                                case DISK:
                                    printf("Process %d completed disk IO.\n", runningProcess.pid);
                                    runningProcess.priority = 1;
                                    enqueue(&lowPriorityQueue, runningProcess);
                                    break;
                                case TAPE:
                                case PRINTER:
                                    printf("Process %d completed tape/printer IO.\n", runningProcess.pid);
                                    runningProcess.priority = 0;
                                    enqueue(&highPriorityQueue, runningProcess);
                                    break;
                            }
                        }
                    }
                }

                printf("Process %d is running (%d priority / %d remaining cpu time).\n", runningProcess.pid, runningProcess.priority, runningProcess.remaining_cpu_time);

                runningProcess.remaining_cpu_time--;
                runningProcess.current_cpu_time++;
                quantum--;

                current_time++;

                if (runningProcess.remaining_cpu_time == 0) {
                    printf("Time %d: Process %d completed.\n", current_time, runningProcess.pid);
                    printf("Turnaround time for Process %d: %d\n", runningProcess.pid, current_time - runningProcess.start_time);

                    completed_processes++;
                    break; 
                    
                } else if (quantum == 0) {
                    printf("Time %d: Process %d preempted.\n", current_time, runningProcess.pid);
                    runningProcess.status = READY;
                    runningProcess.priority = 1;
                    enqueue(&lowPriorityQueue, runningProcess);
                }
                sleep(1);
            }
        } else {
            current_time++;
            printf("\n");
        }
    }
}

void printProcessTable(Process *processes, int num_processes) {
    printf(" ___________________________________\n");
    printf("|  PID |  cpu_time  | arriving_time |\n");
    printf("|-----------------------------------|\n");
    for (int i = 0; i < num_processes; i++) {
        printf("|  P%d  |     %2d     |      %2d       |\n", processes[i].pid, processes[i].cpu_time, processes[i].arrival_time);
        printf("|-----------------------------------|\n");
    }
    printf("\n");
}

void printWelcomeTable() {
    printf("\n");
    printf("    *********************************************************\n");
    printf("    *                                                       *\n");
    printf("    *                                                       *\n");
    printf("    *    BEM VINDO AO SIMULADOR ROUND ROBIN COM FEEDBACK    *\n");
    printf("    *            ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥              *\n");
    printf("    *                                                       *\n");
    printf("    *              Pressione qualquer tecla                 *\n");
    printf("    *                  para iniciar...                      *\n");
    printf("    *                                                       *\n");
    printf("    *                                                       *\n");
    printf("    *********************************************************\n");
    printf("\n");

    getchar();
}

void printTurnaroundTable(Process *processes, int num_processes) {
    printf("\n\nFIM!!\n");
    sleep(5);
    system("clear");
    printf(" ____________________________________________________\n");
    printf("|  PID |  start_time  | conclusion_time | turnaround  |\n");
    printf("|----------------------------------------------------|\n");
    for (int i = 0; i < num_processes; i++) {
        int turnaround = processes[i].aux - processes[i].start_time;
        printf("|  P%d  |     %2d       |      %2d         |    %2d      |\n", 
            processes[i].pid, processes[i].start_time, processes[i].aux, turnaround);
        printf("|----------------------------------------------------|\n");
    }
    printf("\n");
}


int main() {
    system("clear");

    printWelcomeTable();

    system("clear");

    
    int num_processes = MAX_PROCESSES;
    Process *processes = initializeProcesses(num_processes);
    printProcessTable(processes, num_processes);
    simulateRoundRobin(processes, num_processes);
    printTurnaroundTable(processes, num_processes);
    free(processes);
    return 0;
}

