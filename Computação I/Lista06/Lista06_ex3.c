#include <stdio.h>
int mdc(int num1, int num2) {
    int resto;

    do {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;

    }
    while (resto != 0);

    return num1;
}

int main(){
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("\nO MDC é: %d", mdc(num1, num2));

    return 0;
}
