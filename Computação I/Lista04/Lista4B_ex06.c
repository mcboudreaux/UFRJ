#include <stdio.h>
#include <stdlib.h>

int main(){
    int cont = 1;
    int opc, n;

    while (cont == 1){
        printf("<Convers�o de base>\n");
        printf("1: Decimal para hexadecimal\n");
        printf("2: Hexadecimal para decimal\n");
        printf("3: Decimal para octal\n");
        printf("4: Octal para decimal\n");
        printf("5: Encerra\n");
        scanf("%d", &opc);

        if (opc<1||opc>5){
                printf("\n***OP��O INV�LIDA***");
                printf("\nTente Novamente\n\n");
                break;
                }

        switch (opc){
            case 1:
                printf("Digite o n�mero: ");
                scanf("%d", &n);
                printf ("\nA convers�o do n�mero %d em hexadecimal �: %2X\n",n,n);
                break;

            case 2:
                printf("Digite o n�mero: ");
                scanf("%X", &n);
                printf ("\nA convers�o do n�mero %X em decimal �: %d\n",n,n);
                break;

            case 3:
                printf("Digite o n�mero: ");
                scanf("%d", &n);
                printf ("\nA convers�o do n�mero %d em octal �: %2o\n",n,n);
                break;

            case 4:
                printf("Digite o n�mero: ");
                scanf("%o", &n);
                printf ("\nA convers�o do n�mero %o em hexadecimal �: %2d\n",n,n);
                break;

            case 5:
                exit(EXIT_FAILURE);
            }
        printf("\nDeseja continuar? (1)Sim (0)N�o\n");
        scanf("%d", &cont);
        printf("\n");


    }

    return 0;
}
