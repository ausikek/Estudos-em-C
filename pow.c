#include <stdio.h>

double myPow(double x, int n);

int main(void) {

    printf("%f", myPow(2, 2000));

    return 0;
}

double myPow(double x, int n) {
    
    int isNegative = 0;

    if (n < 0) {

        isNegative = 1;
        
        switch (n) {

            case -2147483648:
                
                n = (unsigned int) n;

                break;
            
            default:
                
                n = -n;

                break;

        }
        
    }
    
    if (n == 0 || x == 1) return 1;
    if (x == 0) return 0;
    if (n==1) return x;

    x = x * myPow(x, n - 1);

    return isNegative ? (double) 1 / x : x;
}