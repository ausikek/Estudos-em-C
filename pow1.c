#include <stdio.h>

int main(void) {

    printf("%f", myPow(2.1, 3));

    return 0;
}


double myPow(double x, int n) {
    
    if ((double) x == 1 || n == 0) {

        return 1;

    }

    double y = x;
    unsigned int m = 0;

    if (n = -2147483648) {

        n = n + 1;
        n = - n;
        m = n;
        m = m + 1;
        n = -n;

    } else {

        m = (n > 0 ? n : -n);

    }

    while (m > 1) {

        x = x * y;

        m = m - 1;

    }

    if (n > 0) return x;
    
    else return (double) 1 / x ;
}