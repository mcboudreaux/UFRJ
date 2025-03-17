#include <stdio.h>
int strlen(char str[]){
    int tam = 0;

    while(str[tam] != '\0'){
        tam++;
    }
    return tam;
}

int strcmp(char v1[], char v2[]){
    int comp;
    if (strlen(v1)>strlen(v2)){
        comp = 1;
    }
    if (strlen(v1)<strlen(v2)){
        comp = -1;
    }
    if (strlen(v1)==strlen(v2)){
        comp = 0;
    }

    return comp;
}

int strcat(char v1[], char v2[]) {
    int i, j;

    i = strlen(v1);

    for (j = 0; v2[j] != 0; i++, j++) {
        v1[i] = v2[j];
    }

    v1[i] = 0;
    return v1;
}

int main(){
    char v1[10] = "123454321";
    char v2[5] = "0987";

    printf("O tamanho de v1 é: %d\n", strlen(v1));
    printf("O tamanho de v2 é: %d\n", strlen(v2));

    printf("Comparação: %d",strcmp(v1, v2));
    printf("\nConcanetação: %s",strcat(v1, v2));


    return 0;
}
