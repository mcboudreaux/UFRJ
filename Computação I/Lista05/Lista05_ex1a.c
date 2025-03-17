#include <stdio.h>
#include <stdlib.h>

int main(){
    char string1[61], string2[61];
    char aux1[61], aux2[61], crt;
    int a, b, aux = 0;

    printf("Digite a primeira string: ");
    scanf("%s",&string1);

    printf("Digite a segunda string: ");
    scanf("%s",&string2);


    printf("\n< MENU >\n");
    b = strlen(string1)-1;
    for(a = 0; string1[a]!='\0'; a++){
       aux1[b] = string1[a];
       b--;
       }
    aux1[a]='\0';

    b = strlen(string2)-1;
    for(a = 0; string2[a]!='\0'; a++){
       aux2[b] = string2[a];
       b--;
       }
    aux2[a]='\0';

    printf("a. As strings invertidas:\nprimeira:%s\nsegunda:%s\n",aux1, aux2);

    printf("\nb. As duas strings em outro vetor:");

    b = strlen(string1)-1;
    for(a = 0; a<=b; a++){
       aux1[a] = string1[a];
       }
    printf("\nprimeira: %s", aux1);

    b = strlen(string2)-1;
    for(a = 0; a<=b; a++){
       aux2[a] = string2[a];
       }
    printf("\nsegunda: %s\n", aux2);

    printf("\nc. Compare as duas strings e informe quem é a string maior\n");

    if(strlen(string1)>strlen(string2)){
        printf("A primeira string é maior e possui tamanho %d\n",strlen(string1));
        printf("\nd. A string de maior tamanho é %s\n", string1);
    }
    if(strlen(string1)<strlen(string2)){
        printf("A segunda string é maiore possui tamanho %d\n",strlen(string2));
        printf("\nd. A string de maior tamanho é %s\n", string2);
    }
    if(strlen(string1)==strlen(string2)){
        printf("Ambas possuem o mesmo tamanho, que é %d\n",strlen(string1));
        printf("\nd. A string de maior tamanho: elas tem o mesmo tamanho\nprimeira:  %s\nsegunda: %s\n", string1 ,string2);
    }

    printf("\ne. Identicar a ocorrência de determinado caractere na string:\n");
    printf("Informe o caractere: ");
    scanf("%s",&crt);

    b = strlen(string1);
    for(a = 0; a<b; a++){
        if (string1[a]==crt){
            printf("O caractere está presente na primeira string na posição %d\n",a);
            aux = 1;
        }
    }
    b = strlen(string2);
    for(a = 0; a<b; a++){
        if (string2[a]==crt){
            printf("O caractere está presente na segunda string na posição %d\n",a);
            aux = 1;
        }
    }
    if (aux == 0){
        printf("O caractere não está presente em nenhuma das strings");
    }


    return 0;

}
