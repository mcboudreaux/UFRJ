#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void){
    int i, n;
    float par = 0, impar = 0;
    int max = 100;

    srand(time(NULL));
    for (i = 0; i < 1000000; i++){
        n = rand();
        n = n % max;
        if(n%2==0){
            par = par+1;
        }else{
            impar = impar+1;
        }
    }
    par = par/10000;
    impar = impar/10000;
    printf("par: %f%%\nimpar: %f%%",par,impar);
    return 0;
}

//Programa tende a gerar n�meros pares, por�m, apresentou uma margem de diferen�a muito pequena, havendo exce��es.
