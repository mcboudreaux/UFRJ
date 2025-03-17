//Escreva um programa que lê um número inteiro e um número fracionário, e imprime os valores lidos e seus respectivos endereços.
#include <stdio.h>
int  main() {

    int num;
    float frac;
    // Lendo um número inteiro e número fracionário
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    printf("Digite um número fracionário: ");
    scanf("%f", &frac);
    printf("\nO número é inteiro é %d\n O número fracionário é %f\n", num, frac);
    // Imprime o local da memória onde a informação está armazenada (ponteiro)
    printf("\nO endereco do número é inteiro é %p \nO endereco número fracionário é %p \n", &num);
    return 0;

}
