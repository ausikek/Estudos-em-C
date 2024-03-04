#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 70


int moveMaker(char *tortoise_pos, char *hare_pos);


int main(void) {

    srand(time(NULL));

    char tortoise_position[SIZE] = {'T'};
    char hare_position[SIZE] = {'H'};

    for (size_t i = 1; i < SIZE; i++) {

        tortoise_position[i] = '-';
        hare_position[i] = '-';

    }

    puts("BANG !!!!");
    puts("AND THEY'RE OFF !!!!");

    int sentinel = 0;

    while (sentinel != -1) {

        for (size_t j = 0; j < SIZE; j++) {

            printf("%c", tortoise_position[j]);

        }

        puts(" ");

        for (size_t j = 0; j < SIZE; j++) {

            printf("%c", hare_position[j]);

        }

        puts("\n\n");

        int x = moveMaker(tortoise_position, hare_position);

        sentinel = x;

        if (x == -1) {

            for (size_t j = 0; j < SIZE; j++) {

                printf("%c", tortoise_position[j]);

            }

            puts(" ");

            for (size_t j = 0; j < SIZE; j++) {

                printf("%c", hare_position[j]);

            }

            puts("\n\n");

        }
    }

    return 0;

}


int moveMaker(char *tortoise_pos, char *hare_pos) {

    int moveGenerator(void);
    void swap(char *idxPtr1, char *idxPtr2);


    int t_move = moveGenerator();

    //printf("\n %d xxx \n", t_move);

    static size_t t_index = 0;
    static size_t h_index = 0;
    

    switch (t_move)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        // FAST PLOD: 3 SQUARES FORWARD
        if (t_index + 3 < 70) {

            swap(&tortoise_pos[t_index], &tortoise_pos[t_index + 3]);
            
            t_index = t_index + 3;


        } else if(t_index + 3 >= 70) {

            swap(&tortoise_pos[t_index], &tortoise_pos[69]);

            t_index = 69;

        }

        break;
    case 6:
    case 7:
        // SLIP: 6 SQUARES BACKWARDS

        if (t_index > 6) {

            swap(&tortoise_pos[t_index], &tortoise_pos[t_index - 6]);

            t_index = t_index - 6;

        } else if (t_index <= 6) {

            swap(&tortoise_pos[t_index], &tortoise_pos[0]);

            t_index = 0;

        }

        break;
    case 8:
    case 9:
    case 10:
        // SLOW PLOD: 1 SQUARE FORWARD

        if (t_index + 1 < 70) {

            swap(&tortoise_pos[t_index], &tortoise_pos[t_index + 1]);
            
            t_index = t_index + 1;


        } else if (t_index + 1 >= 70) {

            swap(&tortoise_pos[t_index], &tortoise_pos[69]);

            t_index = 69;

        }

        break;
    
    default:
        break;
    }


    int h_move = moveGenerator();

    //printf("\n %d xxxX \n", h_move);

    switch (h_move)
    {
    case 1:
    case 2:
        // SLEEP: NO MOVES
        
        break;
    case 3:
    case 4:
        // BIG HOP: 9 SQUARES FORWARD

        if (h_index + 9 < 70) {

            swap(&hare_pos[h_index], &hare_pos[h_index + 9]);
            
            h_index = h_index + 9;


        } else if (h_index + 9 >= 70) {

            swap(&hare_pos[h_index], &hare_pos[69]);

            h_index = 69;

        }

        break;
    case 5:
        // BIG SLIP: 12 SQUARES BACKWARDS

        if (h_index > 12) {

            swap(&hare_pos[h_index], &hare_pos[h_index - 12]);
            
            h_index = h_index - 12;


        } else if (h_index <= 12) {

            swap(&hare_pos[h_index], &hare_pos[0]);

            h_index = 0;

        }

        break;
    case 6:
    case 7:
    case 8:
        // SMALL HOP: 1 SQUARE FORWARD

        if (h_index + 1 < 70) {

            swap(&hare_pos[h_index], &hare_pos[h_index + 1]);
            
            h_index = h_index + 1;


        } else if (h_index + 1 >= 70) {

            swap(&hare_pos[h_index], &hare_pos[69]);

            h_index = 69;

        }

        break;
    case 9:
    case 10:
        // SMALL SLIP: 1 SQUARE BACKWARDS

        if (h_index > 1) {

            swap(&hare_pos[h_index], &hare_pos[h_index - 1]);
            
            h_index = h_index - 1;


        } else if (h_index <= 1) {

            swap(&hare_pos[h_index], &hare_pos[0]);

            h_index = 0;

        }

        break;
    
    default:
        break;
    }

    if (t_index == 69) {

        printf("TORTOISE WINS!!!\n");
        return -1;

    } else if (h_index == 69) {

        printf("Hare Wins\n");
        return -1;

    } else if (t_index == h_index) {

        printf("\nOUCH!!!\n\n");

    } else {

        return 0;

    }
}


int moveGenerator(void) {

    int animal_move = 1 + rand() % 10; 

    return animal_move;

}

void swap(char *idxPtr1, char *idxPtr2) {

    char hold = *idxPtr2;
    *idxPtr2 = *idxPtr1;
    *idxPtr1 = hold;

}