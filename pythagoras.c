#include <stdio.h>

int main(void) {

    unsigned int a;
    unsigned int b;
    unsigned int c;

    for (a = 1; a <= 500; a++) {

        for (b = 1; b <= 500; b++) {

            for (c = 1; c <= 500; c++) {

                if (a*a == b*b + c*c) {

                    printf("a = %u, b = %u, c = %u", a, b, c);
                    printf("\n");

                }
            }
        }
    }

    return 0;
}