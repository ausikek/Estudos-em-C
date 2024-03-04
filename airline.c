#include <stdio.h>

#define SIZE 10

int *firstClass(int *array);
int *economyClass(int *array);

int main(void) {

    int ticket;

    int sentinel = 0;

    int plane[SIZE] = {0};

    int *n;

    while (sentinel == 0) {

        int booking = 0;

        if (booking == 10) {

            puts("The airplane is at full capacity. The next flight is in three hours.");
            break;

        }

        puts("----WELCOME TO C AIRLINES----");
        puts("Please type 1 for \"first class\"");
        puts("Please type 2 for \"economy\"");

        scanf("%d", &ticket);

        if (ticket == 1) {

            n = firstClass(plane);

            puts("Would you like to buy another ticket? Press 1 for YES or 2 for NO.");

            int decision = 0;

            scanf("%d", &decision);

            if (decision == 1) {

                continue;

            } else {

                sentinel = -1;

                puts("Next flight leaves in 3 hours.");

            }

        } else if (ticket == 2) {

            n = economyClass(plane);

            puts("Would you like to buy another ticket? Press 1 for YES or 2 for NO.");

            int decision = 0;

            scanf("%d", &decision);

            if (decision == 1) {

                continue;

            } else {

                sentinel = -1;

                puts("Next flight leaves in 3 hours.");

            }
        
        } else {

            puts("Please insert an accepted value.");

        }

        for (size_t i = 0; i < SIZE; i++) {

            if (n[i] == 1) {

                booking++;
                printf("%d", booking);

            }
        }
    }

    return 0;
}

int *firstClass(int *array) {

    for (size_t i = 0; i < SIZE - 5; i++) {

        if (array[i] == 0) {

            array[i] = 1;

            printf("----BOARDING PASS----\n    SEAT %d FIRST CLASS\n", i + 1);

            puts("---------------------");

            break;

        } else if (array[0] == 1 && array[1] == 1 && array[2] == 1 && array[3] == 1 && array[4] == 1) {

            int decision;

            puts("The first class is full. Would you like to fly the economy class?");
            puts("Please type 1 for \"economy\"");
            puts("Please type 2 for exiting");
            scanf("%d", &decision);

            if (decision == 1) {

                economyClass(array);

            } else if (decision == 2) {

                puts("Next flight leaves in 3 hours.");

                break;

            }
        }
    }
    return array;
}

int *economyClass(int *array) {

    for (size_t i = 5; i < SIZE; i++) {

        if (array[i] == 0) {
            
            array[i] = 1;

            printf("----BOARDING PASS----\n    SEAT %d ECONOMY\n", i + 1);

            puts("---------------------");

            break;

        } else if (array[5] == 1 && array[6] == 1 && array[7] == 1 && array[8] == 1 && array[9] == 1) {

            int decision;

            puts("The economy class is full. Would you like to fly the first class?");
            puts("Please type 1 for \"first class\"");
            puts("Please type 2 for exiting");
            scanf("%d", &decision);

            if (decision == 1) {

                firstClass(array);

            } else if (decision == 2) {

                puts("Next flight leaves in 3 hours.");
                
                break;

            }
        }
    }
    return array;
}