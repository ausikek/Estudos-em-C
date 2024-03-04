#include <stdio.h>

int main(void) {

    int total;
    int smallest;
    int number;
    unsigned int i;

    printf("Insert how many numbers you want to compare: \n");
    scanf("%d", &total);

    if (total > 0) {

        printf("Insert a number: \n");
        scanf("%d", &smallest);

        for (i = 2; i <= total; i++) {

            printf("Insert a number: \n");
            scanf("%d", &number);
            
            if (number < smallest) {

                smallest = number;

            }

        }

        printf("The smallest number is %d", smallest);

    } else {

        printf("The program will exit");

    }

    return 0;
}