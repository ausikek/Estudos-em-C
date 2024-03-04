#include <stdio.h>

void hanoi(int number);

int main(void) {

    int disks;

    printf("Insert the number of disks: \n");
    scanf("%d", &disks);

    hanoi(disks);

    return 0;
}

void hanoi(int number) {

    for (int i = 1; i < (1 << number); i++) {

        printf( "%d -> %d.\n",(i&i-1) % 3, ((i|i-1)+1) % 3 );
    
    }
}

//  00000010 
//  00000001
// &--------
//  00000000 % 3 = 0

//  00000001
//  00000000
// /--------
//  0000001 + 1 = 000000001 % 3 = 2