#include <stdio.h>
#include <conio.h>

#define Z 5   

#define SQR(a)    ((a)*(a))
#define MAX(a,b)  (((a)>(b))?(a):(b))
#define MIN(a,b)  (((a)<(b))?(a):(b))
#define ABS(a)    (((a)<0)?-(a):(a))
#define PRINTR(w) printf(#w " = %f\n", (float)(w))

#ifndef UNIT_TEST
int main(void)
{
    float x, y, w;
    char ch;

    do {
        printf("x = "); scanf("%f", &x);
        printf("y = "); scanf("%f", &y);

#if (Z >= 1) && (Z < 10)
        w = SQR(MAX(x + y, x + Z));
#else
        w = MIN(SQR(x), 5 * ABS(y - Z));
#endif

        PRINTR(w);
        puts("Repeat? y/n");
        ch = getch();
    } while (ch == 'y');

    return 0;
}
#endif