#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

void bubblesort(int array[]);

int main(void) {

    srand(time(NULL));
    
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {

        arr[i] = rand();

    }

    puts("Original Array");

    for (size_t i  = 0; i < SIZE; i++) {

        printf("%d ", arr[i]);

    }

    puts(" ");

    bubblesort(arr);

    return 0;
}

void bubblesort(int array[]) {

    for (int pass = 1; pass < SIZE; pass++) {

        for (size_t i = 0; i < SIZE -1; i++) {

            if (array[i] > array[i+1]) {

                int hold = array[i];

                array[i] = array[i+1];

                array[i+1] = hold;

            }
 
        }

    }

    puts("Sorted Array");

    for (size_t i  = 0; i < SIZE; i++) {

        printf("%d ", array[i]);

    }

}
