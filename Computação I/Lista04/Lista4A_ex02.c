#include <stdio.h>
int main(){

    int nlinha, ncoluna = 1, aux = 1;

    printf("Digite o número de linhas: ");
    scanf("%d", &nlinha);

    if(nlinha<=0){
        printf("***NÚMERO INSERIDO INVÁLIDO***\n");
        return 0;
    }

    while (nlinha>0){

        while (ncoluna>0){
            printf("*");
            ncoluna = ncoluna-1;
        }
        aux = aux+1;
        ncoluna = aux;
        nlinha = nlinha-1;
        printf("\n");

    }

    return 0;


}
