#include <stdio.h>
int main(){
    int idade, npessoas;
    int cont = 0, maior = 0, menor = 1000;
    float  med, soma = 0;

    while (idade!=0){
        printf("Digite a %d� idade: ", cont+1);
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
             printf("\n***N�MERO INV�LIDO***\nTente novamente:\n\n");

        }
    }
    med = soma/cont;

    printf("\nO n�mero de pessoas �: %d ", cont);
    printf("\nA idade m�dia do grupo �: %.2f", med);
    printf("\nA menor idade do grupo �: %d", menor);
    printf("\nA maior idade do grupo �: %d\n", maior);

    return 0;
}
