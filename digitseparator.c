#include <stdio.h>

int main(void) {

    int num;

    printf("Input a five digit number:\n");
    scanf("%d", &num);

    int a = (num - (num % 10000)) / 10000;
    int b = ((num % 10000) - (num % 1000)) / 1000;
    int c = ((num % 1000) - (num % 100)) / 100;
    int d = ((num % 100) - (num % 10)) / 10;
    int e = num % 10;

    printf("%d %d %d %d %d", a, b, c, d, e);
    return 0;

}