
#include <stdio.h>
int  main() {

    int num; char newline = "\n";
    // Lendo um n�mero inteiro
    printf("Digite um n�mero: ");
    scanf("%d", &num);
    // Imprime na tela o valor do n�mero, \n indica nova linha
    printf("O n�mero � %d%c", num, newline);
    // Imprime o local da mem�ria onde a informa��o est� armazenada (ponteiro)
    printf("O endere�o � %p\n", &num);
    return 0;

}
