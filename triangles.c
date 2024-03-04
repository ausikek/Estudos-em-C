#include <stdio.h>

int main(void) {

    printf("\n");

// Primeiro Triângulo

    int j;
    int i;

    for (j = 1; j <= 10; j++) {

        for (i = 1; i <= j; i++) {

        printf("%s", "*");

        }

        printf("\n");

    }

    printf("\n");

// Segundo Triângulo

    for (j = 10; j >= 1; j-- ) {

        for (i = 1; i <= j; i++) {

            printf("%s", "*");

        }

        printf("\n");

    }

// Terceiro Triângulo

    for (j = 10; j >= 1; j--) {

        printf("\n");

        if (j == 10) {

            for (i = 1; i <= j; i++) {

                printf("%s", "*");

            }

        } else {

            for (i = j; i < 10; i++) {

                printf(" ");

            }

            for (i = 1; i <= j; i++) {

                printf("%s", "*");

            }

        }

    }

    printf("\n");

// Quarto Triângulo

    for (j = 1; j <= 10; j++) {

        printf("\n");

        if (j == 10) {

            for (i = 1; i <= j; i++) {

                printf("%s", "*");

            }

        } else {

            for (i = 1; i <= 10 - j; i++) {

                printf(" ");

            }

            for (i = 1; i <= j; i++) {

                printf("%s", "*");

            }

        }

    }
    
    return 0;
}

