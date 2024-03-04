#include <stdio.h>

#define SIZE 10000

int recursiveBinarySearch(int array[], int key, size_t low, size_t high);

int main(void) {

    int list[SIZE];

    int key;

    scanf("%d", &key);

    for (size_t i = 0; i < SIZE; i++) {

        list[i] = 2 * i;
 
    }

    int idx = recursiveBinarySearch(list, key, 0, SIZE - 1);

    if (idx != -1) {

        printf("INDEX IS: %d", idx);

    } else {

        printf("Key not found");

    }

    return 0;
}

int recursiveBinarySearch(int array[], int key, size_t low, size_t high) {

    if (low <= high) {

        size_t middle = (high + low) / 2;

        if (key == array[middle]) {

            return middle;

        } else if (key < array[middle]) {

            recursiveBinarySearch(array, key, low, middle - 1);

        } else if (key > array[middle]) {

            recursiveBinarySearch(array, key, middle + 1, high);

        } 
    }
    return -1;
}