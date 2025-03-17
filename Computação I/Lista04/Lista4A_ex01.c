#include <stdio.h>
int main(){

    int nlinha, ncoluna, aux;

    printf("Digite o número de linhas: ");
    scanf("%d", &nlinha);
    printf("Digite o número de colunas: ");
    scanf("%d", &ncoluna);
    aux = ncoluna;
    printf("\n");

    if(nlinha<=0||ncoluna<=0){
        printf("***NÚMERO INSERIDO INVÁLIDO***\n");
        return 0;
    }

    while (nlinha>0){
        while (ncoluna>0){
            printf("*");
            ncoluna = ncoluna - 1;
        }
        nlinha = nlinha-1;
        ncoluna = aux;
        printf("\n");
    }

    return 0;

}
