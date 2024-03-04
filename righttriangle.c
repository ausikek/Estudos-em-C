#include <stdio.h>

int main(void) {

    unsigned int a;
    unsigned int b;
    unsigned int c;

    printf("Enter hypotenuse: ");
    scanf("%d", &a);

    printf("Enter side 1: ");
    scanf("%d", &b);

    printf("Enter side 2: ");
    scanf("%d", &c);

    if (a*a == b*b + c*c) {
        
        printf("Right Triangle");

    } else {

        printf("Not a Right Triangle");

    }

    return 0;
}