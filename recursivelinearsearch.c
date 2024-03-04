#include <stdio.h>

#define SIZE 100

int recursiveLinearSearch(int array[], int key, size_t size);

int main(void) {

    int list[SIZE];

    int key;

    scanf("%d", &key);

    for (size_t i = 0; i < SIZE; i++) {

        list[i] = 2 * i;

    }

    int x = recursiveLinearSearch(list, key, SIZE);

    if (x != -1) {

        printf("index is: %d", x);

    } else {

        printf("Key not found.");

    }

    return 0;
}

int recursiveLinearSearch(int array[], int key, size_t size)  {

    size_t f_idx = size - 1;

    if (size > 0) {

        if (array[f_idx] == key) {

            return f_idx;

        } else if (array[f_idx] != key) {

            recursiveLinearSearch(array, key, f_idx);

        } else {

            return -1;

        }
    }
}
