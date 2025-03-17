#include <stdio.h>
int mmc(int num1, int num2) {

    int resto, a, b;

    a = num1;
    b = num2;

    do{
        resto = a % b;
        a = b;
        b = resto;
    }
    while (resto != 0);

    return ( num1 * num2)/a;
}

int main(){
    int num1, num2;

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &num1);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);

    printf("\nO MMC �: %d", mmc(num1, num2));

    return 0;
}
