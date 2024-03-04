#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main(void) {

    srand(time(NULL));

    int arr[SIZE] = {0}; 

    int duplicate = 0;

    for (size_t i = 0; i < SIZE; i++) {

        arr[i] = 10 + rand() % 91; 
        
        for(size_t j = 0; j < SIZE; j++) {

            if (arr[i] == arr[j] && i != j) {

                duplicate = 1;

            } else {

                continue;

            }

        }

        if (duplicate == 0) {

            printf("%d ", arr[i]);

        }

        duplicate = 0;

    }

    printf("\n");

    for (size_t k = 0; k < SIZE; k++) {

        printf("%d ", arr[k]);

    }

    return 0;
}