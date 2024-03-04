#include <stdio.h>

int main(void) {
    
    printf("Insira um numero:\n");

    int num1;

    scanf("%d", &num1);

    if (num1 % 2 == 0) {
        printf("Numero par");
    } else {
        printf("Numero impar");
    }
    
    return 0;
}