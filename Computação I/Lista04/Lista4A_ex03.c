#include <stdio.h>
int main(){

    int nlinha, ncoluna = 1, aux = 1;

    printf("Digite o n�mero de linhas: ");
    scanf("%d", &nlinha);

    if(nlinha<=0){
        printf("***N�MERO INSERIDO INV�LIDO***\n");
        return 0;
    }

    while (nlinha>0){
        aux = nlinha;
        while (aux>0){
            printf("*");
            aux= aux-1;
        }
        nlinha= nlinha-1;
        printf("\n");
    }
    return 0;

}
