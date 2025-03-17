#define DIML 2
#define DIMC 3
#include <stdio.h>

int main(){
    int i, j;
    int matriz1 [50][50];
    int matriz2 [50][50];
    int matriz_soma [50][50];

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
    printf("A soma das matrizes é:");

    for (i=0; i< DIML; i++){
        printf("\n");
        for (j=0; j< DIMC; j++){
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("%3d", matriz_soma[i][j]);
        }
    }
    return 0;
}
