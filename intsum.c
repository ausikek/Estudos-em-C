#include <stdio.h>

int main(void)

{
    int num1;
    int num2;

    printf("Insira o primeiro numero: ");
    scanf("%d", &num1);

    printf("Insira o segundo numero: ");
    scanf("%d", &num2);

    int num3;
    
    num3 = num1 + num2;

    printf("A soma e %d", num3);
}
