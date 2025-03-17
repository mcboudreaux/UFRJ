#include <stdio.h>

int main () {
    float notaAluno ;
    float mediaAluno = 0.0;
    int notasLidas = 0;
    int quantProvas;

    printf("Insira a quantidade de notas: ");
    scanf("%d", &quantProvas);
    if (quantProvas<0){
        printf("\n***NUMERO INVALIDO***\n");
        return 0;
        }

    while ( notasLidas < quantProvas ) {
        notasLidas = notasLidas +1;
        printf("Insira a %d° nota do aluno: ", notasLidas);
        scanf("%f", &notaAluno);
        if (notaAluno<0||notaAluno>10){
            printf("\n***NOTA INSERIDA INVALIDA***\n");
            return 0;
        }
        mediaAluno = mediaAluno+ notaAluno;
    }

    mediaAluno = mediaAluno / quantProvas ;
    printf ("\nA media do aluno foi %.2f\n", mediaAluno );

    if ( mediaAluno >= 5.0) {
        printf (" Aprovado \n");
    }
    else {
    printf (" Reprovado ");
    }

    return 0;
}
