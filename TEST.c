#include <stdio.h>

int main(void) {

    int x = -2147483648;
    x = (unsigned int) x;
    printf("%u", x);
}