#include <stdio.h>

#define SIZE 50

int main(void) {

    int floor[SIZE][SIZE] = {0,0};

    int monitor[6] = {0, 0, 0, 0, 0, 0};   // {position x, position y, direction, pen status, command, sentinel}

    while (monitor[5] == 0) {

        printf("The current turtle position is LINHA: %d; COLUNA: %d.\n", monitor[0], monitor[1]);
        printf("@ ");
        scanf("%d", &monitor[4]);
        printf("\n\n");

        int places;
        int initial;
        int end;

        switch (monitor[4])
        {
        case 1:
            
            printf("Pen is up.\n");
            monitor[3] = 0;
            
            break;

        case 2:

            printf("Pen is down.\n");
            monitor[3] = 1;
        
            break;

        case 3:

            printf("The turtle turned right.\n");
            monitor[2]++;

            break;

        case 4:

            printf("The turtle turned left.\n");
            monitor[2]--;

            break;

        case 5:

            places = 0;

            scanf("%d", &places);

            if (monitor[3] == 1) {

                switch (monitor[2] % 4) {
                
                    case 0:

                        initial = monitor[1];

                        end = monitor[1] + places;
                        
                        for (initial; initial <= end; initial++) {

                            floor[monitor[0]][initial] = 1;

                        }

                        monitor[1] = monitor[1] + places;
                        

                        break;

                    case 1:

                        initial = monitor[0];

                        end = monitor[0] + places;

                        for (initial; initial <= end; initial++) {

                            floor[initial][monitor[1]] = 1;

                        }

                        monitor[0] = monitor[0] + places;

                        break;
                    
                    case 2:

                        initial = monitor[1];

                        end = monitor[1] - places;
                        
                        for (initial; initial >= end; initial--) {

                            floor[monitor[0]][initial] = 1;

                        }

                        monitor[1] = monitor[1] - places;

                        break;

                    case 3:

                        initial = monitor[0];

                        end = monitor[0] - places;

                        for (initial; initial >= end; initial--) {

                            floor[initial][monitor[1]] = 1;

                        }

                        monitor[0] = monitor[0] - places;

                        break;

                    default:
                        
                        break;
                    
                }

            } else if (monitor[3] == 0) {

                switch (monitor[2] % 4) {
                    
                    case 0:
                        
                        monitor[1] = monitor[1] + places;
                        
                        break;

                    case 1:

                        monitor[0] = monitor[0] + places;

                        break;
                    
                    case 2:

                        monitor[1] = monitor[1] - places;

                        break;

                    case 3:

                        monitor[0] = monitor[0] - places;

                        break;

                    default:
                        
                        break;
                
                }
            }

            break;

        case 6:

            for (size_t i = 0; i < SIZE; i++) {

                for (size_t j = 0; j < SIZE; j++) {

                    if (floor[i][j] == 0) {

                        printf(" ");

                        printf(" ");

                    } else {

                        printf("*");

                        printf(" ");

                    }
                }
            
                printf("\n");

            }
        
        case 9:

            monitor[5] = 1;

            break;

        default:

            break;
        
        }
    }

    return 0;
}
