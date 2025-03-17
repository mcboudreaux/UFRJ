#include <stdio.h>

int main () {
    float notaAluno ;
    float mediaAluno ;

    printf("Insira a primeira nota do aluno: ");
    scanf("%f", &notaAluno);
    if (notaAluno<0||notaAluno>10){
        printf("\n***NOTA INSERIDA INVALIDA***\n");
        return 0;
    }
    mediaAluno = notaAluno;

    printf("Insira a segunda nota do aluno: ");
    scanf("%f", &notaAluno);
    if (notaAluno<0||notaAluno>10){
        printf("\n***NOTA INSERIDA INVALIDA***\n");
        return 0;
    }
    mediaAluno = mediaAluno + notaAluno;

    printf("Insira a terceira nota do aluno: ");
    scanf("%f", &notaAluno);
    if (notaAluno<0||notaAluno>10){
        printf("\n***NOTA INSERIDA INVALIDA***\n");
        return 0;
    }

    mediaAluno = mediaAluno + notaAluno;
    mediaAluno = mediaAluno/3;

    if( mediaAluno >= 5.0) {
        printf ("\n Aprovado \nmedia: %.2f\n",mediaAluno);
    }
    else {
        printf ("\n Reprovado \nmedia: %.2f\n",mediaAluno);
    }
    return 0;

}
