#include <stdio.h>

int main(void) {

    unsigned int i;
    unsigned int j;

    printf("Decimal to Roman\n");
    printf("--------------------\n");
    printf("Decimal\t\tRoman\n");

    for (i = 1; i <= 100; i++) {

        j = i;

        printf("%u\t\t", j);

        if (j == 100) {
            
            printf("C");
            j = 0;
        
        }

        if (j >= 90 && j < 100) {

            printf("XC");
            j = j - 90;

        }

        if (j >= 50 && j <= 89) {

            printf("L");
            j = j - 50;

        }

        if (j >= 40 && j <= 49) {

            printf("XL");
            j = j - 40;

        }

        while (j >= 10 && j <= 39) {

            printf("X");
            j = j - 10;

        }
        
        if (j >= 5) {

            if (j % 10 == 9) {

                printf("IX");
                j = j - 9;

            } else {

                printf("V");
                j = j - 5;

            }
        }

        while (j > 0) {

            if (j % 4 == 0) {

                printf("IV");
                j = j - 4;

            } else {

                printf("I");
                j = j - 1;

            }

        }
        
        printf("\n");

        }

        return 0;

    }