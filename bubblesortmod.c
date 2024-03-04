#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define S 9

void bubblesort(int array[]);

int main(void) {

    srand(time(NULL));

    // create array

    int a[S];

    for (size_t i = 0; i < S; i++) {

        a[i] = rand();

    }

    // print the original array

    for (size_t j = 0; j < S; j++) {

        printf("%d ", a[j]);

    }

    puts(" ");

    bubblesort(a);

    return 0;
}

void bubblesort(int array[]) {

    int counter = 0;
    
    for (int pass = 1; pass < S; pass++) {

        int max = array[0];
        int index = 0;

// get Max 

        for (size_t i = 1; i < S - counter; i++) {

            if (max < array[i]) {

                max = array[i];
                index = i;

            } 
        }

    if (S-counter != index) {
        
        counter++;

        // sort
        int hold = array[S-counter];
        array[S-counter] = max;
        array[index] = hold;

    } else {
    
    continue;

    }  
}

// print the new array

    for (size_t k = 0; k < S; k++) {

        printf("%d ", array[k]);

    }

}