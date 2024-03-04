#include <stdio.h>

int main(void) {

    unsigned int counter;
    unsigned int number;
    unsigned int largest;

    counter = 1;
    
    while (counter <= 10) {
        printf("Insert a number: ");
        scanf("%d", &number);

        if (number > largest) {

            largest = number;

        }

        counter = counter + 1;

    }

    printf("Largest number: %d", largest);

    return 0;
}
