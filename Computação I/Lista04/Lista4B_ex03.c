#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota, soma = 0;

    for(int i=1; i<4; i++){
        printf("Digite a %d� nota: ", i);
        scanf("%f", &nota);
        if (nota<0) {
            printf("\n***NOTA INV�LIDA***\n");
            exit(EXIT_FAILURE);
        }
        soma = soma + nota;

    }

    printf("\nA m�dia das 3 notas �: %.2f\n",soma/3);

    return 0;
}
