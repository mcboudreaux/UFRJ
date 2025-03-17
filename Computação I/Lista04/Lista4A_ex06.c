#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void){
    int i, n;
    float n1=0, n2=0, n3=0, n4=0, n5=0, n6=0;
    int max = 7;

    srand(time(NULL));
    for (i = 0; i < 6000000; i++){
        n = rand();
        n = n % max;

        switch (n){
            case 0:
                i--;
                break;
            case 1:
                n1++;
                break;
            case 2:
                n2++;
                break;
            case 3:
                n3++;
                break;
            case 4:
                n4++;
                break;
            case 5:
                n5++;
                break;
            case 6:
                n6++;
                break;

        }

    }
    printf("1= %f%%\n", (n1/60000));
    printf("2= %f%%\n", (n2/60000));
    printf("3= %f%%\n", (n3/60000));
    printf("4= %f%%\n", (n4/60000));
    printf("5= %f%%\n", (n5/60000));
    printf("6= %f%%\n", (n6/60000));

    return 0;
}

//As porcentagens são muito próximas, variando apenas a partir da segunda casa decimal
