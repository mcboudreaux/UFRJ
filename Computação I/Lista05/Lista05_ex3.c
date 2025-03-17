#define DIM 10
#include <stdio.h>

int main(){
    int vetor[DIM], i, val;
    int maior = -1000000, menor = 1000000;
    int par=0, soma =0;

    for (i = 0; i < DIM;i++){
        printf("Digite o %d° da sequência: ",i+1);
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

    printf("\nO maior valor da lista é: %d", maior);
    printf("\nO menor valor da lista é: %d", menor);
    printf("\nO número de valores pares é: %d", par);
    printf("\nA soma de todos os valores é: %d\n", soma);

    printf("\nQual valor deseja verificar se está no vetor: ");
    scanf("%d",&val);

    for (i = 0; i < DIM+1;i++){
        if(val==vetor[i]){
            printf("\nValor ESTÁ no vetor na posição (%d)",i+1);
            break;
        }
        if (i==10){
            printf("\nO Valor NÃO ESTÁ no vetor,");
        }
    }


    return 0;
}
