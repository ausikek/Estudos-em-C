#include <stdio.h>

int gcd(int a, int b);

int main(void) {

    int x;
    int y;
    int mdc;

    scanf("%d", &x);
    scanf("%d", &y);
    
    mdc = gcd(x,y);

    printf("The GCD of %d and %d is %d", x, y, mdc);

    return 0;
}

int gcd(int a, int b) {

    int min;
    int mdc;

    if (a < b) {

        min = a;

    } else {

        min = b;

    }

    for (int i = min; i >= 2; i--) {

        if (a % i == 0 && b % i == 0) {

            mdc = i;

            break;

        } else {

            mdc = 1;

        }
        
    }
    
    return mdc; 
}