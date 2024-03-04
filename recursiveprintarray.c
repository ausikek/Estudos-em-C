#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int array[], int size);

int main(void) {

    srand(time(NULL));

    int arr[SIZE];

    for (size_t i = 0; i < SIZE; i++) {

        arr[i] = rand();

    }

    printArray(arr, SIZE);

    return 0;
}

void printArray(int array[], int size) {

    for (size_t j = 0; j < size; j++) {

        printf("%d ", array[j]);

    }

    puts("----------------");

    if (size > 0) {
        
        printArray(array, size - 1);
    
    }
}
