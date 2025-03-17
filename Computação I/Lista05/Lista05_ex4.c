#define DIML 5
#define DIMC 5
#include <stdio.h>

int main(){
    int i, j, k;
    int matriz1 [50][50];
    int matriz2 [50][50];
    int matriz_mult [50][50];

    for (i=0; i< DIML; i++){
        for (j=0; j< DIMC; j++){
            printf("Digite (%d,%d) da primeira matriz: ", i+1, j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\n");

    for (i=0; i< DIML; i++){
        for (j=0; j< DIMC; j++){
            printf("Digite (%d,%d) da segunda matriz: ", i+1, j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }
    printf("\n");
    printf("A multiplicação das matrizes é:");

    for (i=0;i<DIML; i++) {
        for (j=0; j<DIML; j++) {
            for (k=0; k<DIMC; k++) {
                matriz_mult[i][j] = matriz_mult[i][j] + (matriz1[i][k] * matriz2[k][j]);
        }
      }
    }
    printf("\n");

    for (i=0; i<DIML; i++) {
        for (j=0; j<DIMC; j++) {
            printf("%d ", matriz_mult[i][j]);
      }
      printf("\n");
    }


    return 0;
}
