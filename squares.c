#include <stdio.h>

int main(void) {

    unsigned int side;
    unsigned int collumns;
    unsigned int counter;

    collumns = 1;

    printf("Input the side of the square: \n");
    scanf("%d", &side);
    printf(" \n");

    counter = side;

    while (counter > 0) {

        while (collumns <= side) {

            printf("*");
            collumns = collumns + 1;

        }

        collumns = 1;
        counter = counter - 1;
        printf(" \n");
    }

    return 0;
}