#include <stdio.h>

int main(void) {

    unsigned int number;
    unsigned int factorial;

    printf("Insert a number: ");
    scanf("%d", &number);

    unsigned int i;

    i = number;
    factorial = number;

    if (number != 0) {

        while (i > 1) {

            i = i - 1;
            factorial = factorial * i;

        }

        printf("%d", factorial);
    
    } else if (number == 0) {
        
        factorial = 1;
        
        printf("%d", factorial);

    }

    return 0;

}