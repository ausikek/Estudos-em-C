#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define SIZE 1000

void craps(void);
int rollDice(void);
void printArray(int array[]);

int main(void) {    

    craps();
    
    return 0; 
}

void craps(void) {

    int win[SIZE];
    int lose[SIZE];

    for (size_t i = 0; i < SIZE; i++) {

        int myPoint;
        srand(time(NULL));

        int result;
        int counter = 0;
        
        enum Status {CONTINUE,WIN,LOSE};
        enum Status status;
        
        result = rollDice();
        
        switch (result) {
            
            case 7:
            case 11:
                status = WIN;
                counter++;
            
            case 2:
            case 3:
            case 12:
                status = LOSE;
                counter++;
            
            default:
                status = CONTINUE;
                myPoint = result;

            while (status == CONTINUE) {
                
                counter++;

                result = rollDice();
                
                if (result == myPoint){
                    
                    status = WIN;
                
                } else if (result == 7){
                    
                    status = LOSE;
                
                }
            }			
            
            if (status == WIN) {
                
                win[i] = counter;
            
            } else {
                
                lose[i] = counter;
            
            }
        }
    }
    puts("Wins:");
    printArray(win);
    puts("Loses:");
    printArray(lose);

}

int rollDice(void) {
	
    int die1;
	int sum;
	die1 = 1 + (rand() % 6);
	int die2;
	die2 = 1 + (rand() %6 );
	sum = die1 + die2;

	return sum;
}

void printArray(int array[]) {

    for (size_t i = 0; i < SIZE; i++) {

        printf("%d ", array[i]);

    }

    puts(" ");

}