#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fisherYates(int array[], int size);
void print(int array[], int size);


int main(void) {

    srand(time(NULL));

    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    print(array, 10);

    fisherYates(array, 10);

    print(array, 10);

    return 0;
}


void fisherYates(int array[], int size) {

    size_t last_index = size - 1;

    while (last_index > 0) {

        size_t random_index = rand() % last_index;

        int hold = array[last_index];
        array[last_index] = array[random_index];
        array[random_index] = hold;

        last_index--; 

    }
}


void print(int array[], int size) {

    for (size_t i = 0; i < size; i++) {

        printf("%d ", array[i]);

    }

    puts(" ");
}