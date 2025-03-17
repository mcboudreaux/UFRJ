//Maria Carolina Boudreaux Ramirez Deleito
//DRE: 121172871
#include <stdio.h>

int main()
{
    float n1, n2;

    printf("Insira a primeira nota: ");
    scanf("%f", &n1);
    printf("Insira a seguna nota: ");
    scanf("%f", &n2);

    float med = (n1+n2)/2;

    if (med<5){
        printf("\nReprovado! media: %.2f\n",med);
    }
    else{
        printf("\nAprovado! media: %.2f\n",med);
    }

    return 0;
}
