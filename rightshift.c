#include <stdio.h>

#define SHORT __SIZEOF_SHORT__ * 8
#define INT __SIZEOF_INT__ * 8;

void binary(short number);

int main(void) {

    short number = 0;

    scanf("%d", &number);

    binary(number);

    number >>= 4;

    binary(number);

    return 0;
}

void binary(short number) {

    short mask = 1 << 15;

    for (short i = 1; i <= SHORT; i++) {

        printf("%d ", mask & number ? 1 : 0);

        number <<= 1;

        if (i % 8 == 0) printf("  ");

    }

    puts("\n");

}