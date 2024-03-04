#include <stdio.h>

void hanoi(int number, int init_peg, int move_peg, int holding_peg);

int main(void) {

    int n;

    printf("Insert then number of disks: \n");
    scanf("%d", &n);
    
    hanoi(n, 1, 3, 2);
    
    return 0;

}

void hanoi(int number, int init_peg, int final_peg, int inter_peg) {

    if (number == 1) {

        printf("%d -> %d", init_peg, final_peg);
        return;

    }

    hanoi(number - 1, init_peg, inter_peg, final_peg); 
    
    printf("\n%d -> %d\n", init_peg, final_peg);
   
    hanoi(number - 1, inter_peg, final_peg, init_peg);

}