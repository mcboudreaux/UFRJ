#define DIM 10
#include <stdio.h>

int main(){
    int vetor[DIM], i, val;
    int maior = -1000000, menor = 1000000;
    int par=0, soma =0;

    for (i = 0; i < DIM;i++){
        printf("Digite o %d� da sequ�ncia: ",i+1);
        scanf("%d",&vetor[i]);
        if (vetor[i]>maior){
            maior = vetor[i];
        }
        if (vetor[i]<menor){
            menor = vetor[i];
        }
        if(vetor[i] % 2 == 0){
            par++;
        }
        soma = soma+vetor[i];
    }

    printf("\nO maior valor da lista �: %d", maior);
    printf("\nO menor valor da lista �: %d", menor);
    printf("\nO n�mero de valores pares �: %d", par);
    printf("\nA soma de todos os valores �: %d\n", soma);

    printf("\nQual valor deseja verificar se est� no vetor: ");
    scanf("%d",&val);

    for (i = 0; i < DIM+1;i++){
        if(val==vetor[i]){
            printf("\nValor EST� no vetor na posi��o (%d)",i+1);
            break;
        }
        if (i==10){
            printf("\nO Valor N�O EST� no vetor,");
        }
    }


    return 0;
}
