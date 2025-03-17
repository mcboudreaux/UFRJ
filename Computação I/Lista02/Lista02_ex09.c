//Exercıcio 9: Escreva um programa que leia as datas de nascimento de dois amigos e indique quem e o mais velho.
#include <stdio.h>

int main () {
    int dia1,mes1,ano1;
    int dia2,mes2,ano2;

    scanf("%d %d %d", &dia1, &mes1, &ano1);

    if (dia1<1||dia1>31||mes1<1||mes1>12||ano1<1||ano1>2021){
        printf("\n***DATA INVALIDA***\n");
        return 0;
    }

    scanf("%d %d %d", &dia2, &mes2, &ano2);

    if (dia2<1||dia2>31||mes2<1||mes2>12||ano2<1||ano2>2021){
        printf("\n***DATA INVALIDA***\n");
        return 0;
    }

    int data1 = ano1*10000+mes1*100+dia1;
    int data2 = ano2*10000+mes2*100+dia2;

    if (data1<data2){
        printf("\nprimeiro");
        }
    if (data1>data2){
        printf("\nsegundo");
        }
    if (data1==data2){
        printf("\nmesmo dia");
        }

    return 0;
}
