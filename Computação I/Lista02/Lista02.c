//Exercício 5

#include <stdio.h>

int  main() {
    float prova, t1, t2, t3;

    printf("Prova: ");
    scanf("%f", &prova);
    printf("Teste 1: ");
    scanf("%f", &t1);
    printf("Teste 2: ");
    scanf("%f", &t2);
    printf("Teste 3: ");
    scanf("%f", &t3);

    if (prova<0||t1<0||t2<0||t3<0){
        printf("\n***VALOR INSERIDO INVALIDO***\n(Nota negativa)\n");

        return 0;
    }

    if (prova>10||t1>10||t2>10||t3>10){
        printf("\n***VALOR INSERIDO INVALIDO***\n(Nota acima de 10)\n");

        return 0;
    }

    float notaFinal= 0.8*prova+0.2*(t1+t2+t3)/3;

    printf("Nota final %.1f", notaFinal);

    return 0;
}

