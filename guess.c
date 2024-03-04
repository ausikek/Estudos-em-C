#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessPlayer(int guess, int value);

int main(void) {

    srand(time(NULL));

    unsigned int randomNumber = 1 + (rand() % 1000);
    unsigned int firstguess;

    printf("%s", "Guess the number: \n");
    scanf("%u", &firstguess);
    

    guessPlayer(firstguess, randomNumber);

    return 0;

}

void guessPlayer(int guess, int value) {

    int i = 0;

    while (i == 0) {

        if (guess == value) {

            printf("%s","You Won!");
            i = 1;

        } else if (guess < value) {

            printf("%s", "Too low. Try again.\n");
            scanf("%d", &guess);

        } else {

            printf("%s", "Too high. Try again.\n");
            scanf("%d", &guess);

        }

    }

}