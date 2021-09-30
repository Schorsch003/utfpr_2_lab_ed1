#include <stdio.h>
#include <stdlib.h>

int main(){
    system("clear");
    int a = 12, b = 5;
    if(a > b){
        printf("Endereco A = 0x%x \nEndereco B = 0x%x\n", &a, &b);
    }
    else
    {
        printf("Endereco B = 0x%x \nEndereco A = 0x%x\n", &a, &b);
    }
    return 0;
}