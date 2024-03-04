#include <stdio.h>

void square(unsigned int sideNumber, char fillChar);

int main(void) {

    unsigned int side;
    char fill;

    printf("Insert the side lenght: \n");
    scanf("%u", &side);
    
    printf("Insert a character: \n");
    scanf(" %c", &fill);

    printf("\n");

    square(side, fill);

    return 0;
}

void square(unsigned int sideNumber, char fillChar) {

    int i = 1;
    int j = 1;

    for (i; i <= sideNumber; i++) {

        for (j; j<= sideNumber; j++) {

            printf("%c", fillChar);

        }

        printf("\n");
        j = 1;

    }

}