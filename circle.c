#include <stdio.h>

int main(void) {

    float pi = 3.14159;
    float r;

    printf("Insert the radius of the circle:\n");
    scanf("%f", &r);

    float d = 2*r;
    float a = pi * r * r;
    float c = 2 * pi * r;

    printf("The diameter is %f\nThe area is %f\nThe circunference is %f", d, a, c);
    
    return 0;

}