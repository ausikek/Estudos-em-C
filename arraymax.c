#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

void max(int array[]);

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

   max(arr);

    return 0;
}

void max(int array[]) {

    int max = array[0];
    int max_i = 0;

    for (size_t i = 1; i < SIZE; i++) {

        if (max < array[i]) {

            max = array[i];
            max_i = i;

        }

    }
    printf("%d and %d", max, max_i);
}