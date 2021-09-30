#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int a, b, sum, *pointSum;
    a = 12;
    b = 5;
    pointSum = &sum;

    *pointSum = a + b;

    printf("Valor da soma: %d\nEndereco da soma: 0x%x\n", sum, pointSum);

    return 0;
}