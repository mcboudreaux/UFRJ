//Escreva um programa que l� um caractere usando a getchar e exibe o valor atrav�s da putchar.
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
