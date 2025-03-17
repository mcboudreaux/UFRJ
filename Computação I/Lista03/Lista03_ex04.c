#include <stdio.h>
int  main() {
    float A, B, C, d, e, f, g, h;
    float x = 6;
    float y = 2;
    float z = 4;
    float a = 8;
    float b = 7.5;
    float c = 12;

    A = x - y * ++a;
    //B = x - y * a > c % y;
    C = y != c;
    //d = c % y<= y % c;
    e = !(a>b);
    f = ( ( z / a ) + b * --y );
    g = (c=7) || (b<2) ;
    h = (c=7) && (b<2);


    printf("A = %f\n", A);
    //printf("B = %f\n", B);
    printf("C = %f\n", C);
    //printf("d = %f\n", d);
    printf("e = %f\n", e);
    printf("f = %f\n", f);
    printf("g = %f\n", g);
    printf("h = %f\n", h);

    return 0;
}
