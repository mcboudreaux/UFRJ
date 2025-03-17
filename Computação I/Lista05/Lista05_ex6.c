#define DIML 5
#define DIMC 4
#include <stdio.h>

int main(){
    float matriz[DIML][DIMC];
    float maior = 0, soma = 0, matr, med;
    int i, j;

    for (i=0; i< DIML; i++){
        printf("\nDigite os dados do aluno %d�:\n",i+1);
        for (j=0; j< DIMC-1; j++){
            printf("%d� Coluna:",j+1);
            scanf("%f", &matriz[i][j]);
            if (matriz[i][j]<0){
                printf("\n***N�MERO INV�LIDO***\nTente novamente:\n\n");
                j--;
            }
        }
    }
    for (i=0; i< DIML; i++){
        matriz[i][3]=(matriz[i][1]+matriz[i][2])/2;
        soma = soma + matriz[i][3];
        if (matriz[i][3]>maior){
            matr = matriz[i][0];
            maior = matriz[i][3];
        }
    }

    med = soma/5;

    printf("\nA matr�cula do aluno com maior nota �: %.0f", matr);
    printf("\nA m�dia aritm�tica das notas finais �: %.2f", med);


    return 0;
}
