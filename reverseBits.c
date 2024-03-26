#include <stdio.h>

void binary(unsigned int number);
void reverseBits(unsigned int number);

int main(void) {

    unsigned int num = 0;

    scanf("%d", &num);

    binary(num);
    puts(" ");
    reverseBits(num);

    return 0;
}

void binary(unsigned int number) {

    unsigned int mask = 1 << 31;

    for (unsigned int i = 1; i <= 32; i++) {

        printf("%d", number & mask ? 1 : 0);

        number <<= 1;

        if (i % 8 == 0) {

            printf(" ");
        }
    }
}

void reverseBits(unsigned int number) {

    unsigned int mask = 1;

    for (unsigned int i = 1; i <= 32; i++) {

        printf("%d", number & mask ? 1 : 0);

        number >>= 1;

        if (i % 8 == 0) {

            printf(" ");
        }
    }
}