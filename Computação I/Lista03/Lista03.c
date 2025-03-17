#include <stdio.h>
int  main() {
    float D;
    int A, B, C, L;

    A = 5;
    B = 10;
    C = -8;
    D = 1.5;
    L = 0;

    float a = 2 * A % 3 - C;
    float b = (-2*C)/4;
    float c = ((B/3)/3)+D*C/2;
    float d = (-C*2)+(D+B)/A;
    float e = A * C & (L|B);
    float f = (!L + A<C|C+C*B>=1&1);

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("d = %f\n", d);
    printf("e = %f\n", e);
    printf("f = %f\n", f);

    if ((10>5)||(5>10)){
        printf("\na = verdade");
    }else{
        printf("\na = falsa");
    }

    if (!(5==6)&&(5!=6)&&((2>1)||(5<=4))){
        printf("\nb = verdade");
    }else{
        printf("\nb = falsa");
    }

    if ((11>2)&&(5>30)){
        printf("\nc = verdade");
    }else{
        printf("\nc = falsa");
    }

    if ((11>2)||(3>30)){
        printf("\nd = verdade");
    }else{
        printf("\nd = falsa");
    }

    return 0;
}
