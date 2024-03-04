#include <stdio.h>
#include <string.h>

int isPalindrome(char array[], int size);

int main(void) {

    char phrase[] = "radar";
    int lenght = strlen(phrase) - 1;

    int x = isPalindrome(phrase, lenght);

    printf("%d", x);

    return 0;
}

int isPalindrome(char array[], int size) {

    int f_idx = size;

    int i_idx = 0;

    int palindrome = 0;

    if (array[i_idx] == array[f_idx] && i_idx <= f_idx) {

        i_idx++;

        isPalindrome(array, size - 1);

        palindrome = 1;

    }
    
    return palindrome;
}