#include <stdio.h>
int main(){
    int idade, npessoas;
    int cont = 0, maior = 0, menor = 1000;
    float  med, soma = 0;

    while (idade!=0){
        printf("Digite a %d° idade: ", cont+1);
        scanf("%d", &idade);
        if (idade>0){
            if (idade>maior){
                maior = idade;
            }
            if (idade<menor){
                menor = idade;
            }
            cont++;
            soma = soma + idade;
        }
        if (idade<0){
             printf("\n***NÚMERO INVÁLIDO***\nTente novamente:\n\n");

        }
    }
    med = soma/cont;

    printf("\nO número de pessoas é: %d ", cont);
    printf("\nA idade média do grupo é: %.2f", med);
    printf("\nA menor idade do grupo é: %d", menor);
    printf("\nA maior idade do grupo é: %d\n", maior);

    return 0;
}
