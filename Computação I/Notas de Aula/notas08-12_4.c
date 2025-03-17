//Escreva um programa que lê um caractere usando a getchar e exibe o valor através da putchar.
#include <stdio.h>
int  main() {
    char car;

      // Lendo o caractere

     printf("Digite um caractere: ");
     car = getchar();

     // Imprimindo o caractere
    printf("\nO caractere e: ");
    putchar(car);
    return 0;
}
