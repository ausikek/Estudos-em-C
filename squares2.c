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
        j = j + 1;

        while (i <= size) {
        
            printf("*");

            i = i + 1;
    
        }
    }

    printf("\n");

    return 0;
}