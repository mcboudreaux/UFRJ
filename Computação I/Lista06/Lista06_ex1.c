#include <stdio.h>
void conta_vogais (char string [], int vogais []){
    int i, tam;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);
    for(i=0; i<tam; i++){
	    switch(string[i]){
            case 'a':
                vogais[0]++;
                break;
            case 'e':
                vogais[1]++;
                break;
            case 'i':
                vogais[2]++;
                break;
            case 'o':
                vogais[3]++;
                break;
            case 'u':
                vogais[4]++;
                break;
	    }
	}
}
int main(){
    int tam;
    int vogais[5];
    char string[100];
    vogais[0]=0,vogais[1]=0, vogais[2]=0,vogais[3]=0,vogais[4]=0;

    printf("Digite a string: ");
    scanf("%s",&string);

    conta_vogais (string, vogais);
    printf("\nVogal a: %d\n", vogais [0]);
    printf("Vogal e: %d\n", vogais [1]);
    printf("Vogal i: %d\n", vogais [2]);
    printf("Vogal o: %d\n", vogais [3]);
    printf("Vogal u: %d\n", vogais [4]);

    return 0;
}
