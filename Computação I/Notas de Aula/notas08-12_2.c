//Escreva um programa que l� um n�mero inteiro e um n�mero fracion�rio, e imprime os valores lidos e seus respectivos endere�os.
#include <stdio.h>
int  main() {

    int num;
    float frac;
    // Lendo um n�mero inteiro e n�mero fracion�rio
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &num);
    printf("Digite um n�mero fracion�rio: ");
    scanf("%f", &frac);
    printf("\nO n�mero � inteiro � %d\n O n�mero fracion�rio � %f\n", num, frac);
    // Imprime o local da mem�ria onde a informa��o est� armazenada (ponteiro)
    printf("\nO endereco do n�mero � inteiro � %p \nO endereco n�mero fracion�rio � %p \n", &num);
    return 0;

}
