#include <stdio.h>

int factorial(int n) {
    
    unsigned int factorial;

    unsigned int i;

    i = n;
    factorial = n;

    if (n != 0) {

        while (i > 1) {

            i = i - 1;
            factorial = factorial * i;

        }
    
    } else if (n == 0) {
        
        factorial = 1;

    }

    return factorial;

}

int main(void) {

    unsigned int x;
    unsigned int i;
    float k;
    float e;

    i = 0;
    e = 0;

    printf("Enter a value for approximation of Euler's constant: ");
    scanf("%d", &x);

    while (i < x) {
        
        k = 1 / (float) factorial(i);
        e = e + k;
        i = i + 1;
    
    }

    printf("%.10f", e);

    return 0;

}
