#include <stdio.h>

int main(void) {

    unsigned int size;

    printf("Enter size: ");
    scanf("%d", &size);

    unsigned int i;
    unsigned int j;

    j = 1;

    while (j <= size) {

        printf("\n");

        i = 1;

        while (i <= size) {

            if (i == 1 || i == size || j == 1 || j == size) {

                printf("*");

                i = i + 1;

            } else {

                printf(" ");

                i = i + 1;

            }
        
        }

        j = j + 1;

    }

    printf("\n\n");

    return 0;
}