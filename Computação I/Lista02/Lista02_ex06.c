//Exercıcio 6: Escreva um programa que imprima a soma de todos os n ́umeros inteiros entre 0 e N.
//Leia o valor de N do teclado. Nao use comando de repetiçao.

#include <stdio.h>
void adc(int soma,int n){
    soma = soma + n;
    n = n-1;
    cmp(int soma, int n);

}

int cmp(int soma, int n) {
    if (n>0){
        adc(int soma, int n);
    }else {
        return (soma);
    }


}

int  main() {
    int n, soma =0;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    soma = cmp(soma, n);
    printf("%d",soma);

    return 0;
}



