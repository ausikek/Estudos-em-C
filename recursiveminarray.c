#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int minimumArray(int array[], int size);

int main(void) {

    int list[SIZE];

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++) {

        list[i] = rand();
    }

    minimumArray(list, SIZE);

    return 0;
}

int minimumArray(int array[], int size) {

    for (size_t j = size - 1; j > 0; j--) {

        if (array[size-1] < array[size - 2]) {

            int hold = array[size -2];

            array[size-2] = array[size-1];

            array[size-1] = hold;

        }
    }

    for (size_t k = 0; k < size; k++) {

        printf("%d ", array[k]);

    }

    puts(" ");
    
    if (size > 0) {
        
        minimumArray(array, size - 1);
    
    }
    
    return 0;
}

