#include <stdio.h>
#include <stdlib.h>

int main(){
    float total_compra, total_pagar;
    int cod;

    printf("Insira o valor da compra: ");
    scanf("%f", &total_compra);
    printf("\nInforme se o comprador �: \n(1)cliente comum \n(2)funcion�rio \n(3)vip\n\n");
    scanf("%d", &cod);

    switch (cod){
        case 1:
            total_pagar = total_compra;
            break;
        case 2:
            total_pagar = total_compra *0.9;
            break;
        case 3:
            total_pagar = total_compra *0.95;
            break;
        default:
            printf("\n***C�digo Inv�lido***");
            exit(EXIT_FAILURE);
    }

        printf("\nValor total a ser pago �: R$%.2f ", total_pagar);

    return 0;
    }
