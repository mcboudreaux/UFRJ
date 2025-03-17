
#include <stdio.h>
int  main() {

    int num; char newline = "\n";
    // Lendo um número inteiro
    printf("Digite um número: ");
    scanf("%d", &num);
    // Imprime na tela o valor do número, \n indica nova linha
    printf("O número é %d%c", num, newline);
    // Imprime o local da memória onde a informação está armazenada (ponteiro)
    printf("O endereço é %p\n", &num);
    return 0;

}
