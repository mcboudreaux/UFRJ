#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void){
    int i, j, x, y;
    int max = 100;
    float dentro = 0;
    //como o operador módulo não suporta float, considerei 100 como 1.00, podendo aumentar ou diminuir a quantidade de zeros dependendo da precisão requerida.

    srand(time(NULL));
    for (i = 0; i < 1000000; i++){
        x = rand();
        x = x % max;
        y = rand();
        y = y % max;
        if (x+y<=100){
            dentro = dentro+1;
        }
        }

    printf("dentro = %f", (dentro*4)/1000000);

    return 0;
}
