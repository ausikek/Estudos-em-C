#include <stdio.h>

void backwardString(char array[], int size);

int main(void) {

    char string[] = "breno";

    int size = 6;

    printf("%s\n", string);

    backwardString(string, size);

    return 0;

}

void backwardString(char array[], int size) {

    int size_new = size - 2;
    static int left_pointer = 0;

    if (left_pointer <= size_new ) {
    
        char hold = array[size_new];

        array[size_new] = array[left_pointer];
        array[left_pointer] = hold;

        printf("%s\n", array);

        left_pointer++;

    }

    if (left_pointer < size_new) {
        
        backwardString(array, size - 1);
    
    }
}
