#include <stdio.h>

int main()
{
    int a = 41, *p;
    float b = 76, *p1;
    p = &a;
    p1 = &b;
    printf("\nValores antes da modificacao:\n");
    printf("\nA = %d\nB = %f\n", a,b);
    *p = 21;
    *p1 = 42;
    printf("\nValores depois da modificacao:\n");
    printf("\nA = %d\nB = %f\n", a, b);
    return 0;
}