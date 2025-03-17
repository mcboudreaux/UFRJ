#define DIM 5
#include <stdio.h>

int main(){
    int x[50], y[50];
    int soma[50], produto[50], uni[50], igual[50];
    int i, j, aux=0;

    for (i = 0; i < DIM;i++){
        printf("Digite (%d) do vetor x: ", i+1);
        scanf("%d", &x[i]);
        }

    printf("\n");

    for (i = 0; i < DIM;i++){
        printf("Digite (%d) do vetor y: ", i+1);
        scanf("%d", &y[i]);
        }

    printf("\na. Soma entre x e y: ");
    for (i = 0; i < DIM;i++){
        soma[i]=x[i]+y[i];
        printf("%5d",soma[i]);
    }

    printf("\nb. Produto entre x e y: ");
    for (i = 0; i < DIM;i++){
        produto[i]=x[i]*y[i];
        printf("%5d",produto[i]);
    }

    printf("\nc. Diferença entre x e y: ");

    for (i=0;i<DIM; i++) {
        for (j=0; j<DIM; j++) {
            if (x[i]==y[j]){
                igual[aux] =x[i];
                aux++;
                i++;
                j=0;
                }
            }
        printf("%d ",x[i]);

    }

    printf("\nd. Interseção entre x e y: ");

    for (i=0;i<aux; i++){
        printf("%d ",igual[i]);
    }

    printf("\ne. União entre x e y: ");
    for (i=0;i<DIM; i++){
        printf("%d ",x[i]);
    }
    for (i=0;i<DIM; i++) {
        for (j=0; j<DIM; j++) {
            if (y[i]==x[j]){
                i++;
                j=0;
                }
            }
        printf("%d ",y[i]);
    }


    return 0;
}
