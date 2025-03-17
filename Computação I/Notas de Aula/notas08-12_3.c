//Escreva um programa que imprime um caractere usando os formatos para decimal, caractere, hexadecimal e octal.
#include <stdio.h>
int  main() {
     char car;

     printf("Digite um caractere: ");
     scanf("%c", &car);

     printf("\nO caractere em formato decimal é: %d\nO caractere em formato de caractere: %c\nO caractere em formato hexadecimal: %X\nO caractere em formato octal: %o\n", car, car, car, car);
}
