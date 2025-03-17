#include <stdio.h>
#include <stdlib.h>

int main(){
    int cont = 1;
    int opc, n;

    while (cont == 1){
        printf("<Conversão de base>\n");
        printf("1: Decimal para hexadecimal\n");
        printf("2: Hexadecimal para decimal\n");
        printf("3: Decimal para octal\n");
        printf("4: Octal para decimal\n");
        printf("5: Encerra\n");
        scanf("%d", &opc);

        if (opc<1||opc>5){
                printf("\n***OPÇÃO INVÁLIDA***");
                printf("\nTente Novamente\n\n");
                break;
                }

        switch (opc){
            case 1:
                printf("Digite o número: ");
                scanf("%d", &n);
                printf ("\nA conversão do número %d em hexadecimal é: %2X\n",n,n);
                break;

            case 2:
                printf("Digite o número: ");
                scanf("%X", &n);
                printf ("\nA conversão do número %X em decimal é: %d\n",n,n);
                break;

            case 3:
                printf("Digite o número: ");
                scanf("%d", &n);
                printf ("\nA conversão do número %d em octal é: %2o\n",n,n);
                break;

            case 4:
                printf("Digite o número: ");
                scanf("%o", &n);
                printf ("\nA conversão do número %o em hexadecimal é: %2d\n",n,n);
                break;

            case 5:
                exit(EXIT_FAILURE);
            }
        printf("\nDeseja continuar? (1)Sim (0)Não\n");
        scanf("%d", &cont);
        printf("\n");


    }

    return 0;
}
