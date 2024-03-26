#include <stdio.h>

#define CHAR 8
#define UINT 32


void packaging(char charArray[]);
void unpackaging(unsigned int package);
void binary(char character, unsigned int number, unsigned int sentinel);


int main(void) {

    char array[4] = {'k', 'a', 'p', 'o'};

    packaging(array);

    return 0;
}

void packaging(char charArray[]) {

    unsigned int package = charArray[0];

    for (size_t c = 0; c < 4; c++) {

        binary(charArray[c], 0, 0);

    }

    for (size_t i = 1; i < 4; i++) {


        package = package <<= 8;


        package = package | charArray[i];

    }

    printf("\n");

    binary('0', package, 1);

    printf("\n");

    unpackaging(package);

}


void unpackaging(unsigned int package) {

    unsigned int toUnpack = package;

    unsigned int mask = 1 << 31;

        for (unsigned int j = 1; j <= UINT; j++) {

            putchar(toUnpack & mask ? '1' : '0');

            toUnpack <<= 1;

            if (j % 8 == 0) printf("  ");

        }

        printf("\n\n");

        char c1, c2, c3, c4;

        c1 = (package & 4278190080) >> 24;

        c2 = (package & 16711680) >> 16;

        c3 = (package & 65280) >> 8;

        c4 = package & 255;

        char characters[4] = {c1, c2, c3, c4};

        for(unsigned int k = 0; k < 4; k++) {

            binary(characters[k], 0 , 0);

        }
}


void binary(char character, unsigned int number, unsigned int sentinel) {

    if (sentinel == 0) {

        unsigned int mask = 1 << 7;

        for (unsigned int j = 1; j <= CHAR; j++) {

            putchar(character & mask ? '1' : '0');

            character <<= 1;

            if (j % 8 == 0) printf("  ");

        }

        printf("\n");

    } else {

        unsigned int mask = 1 << 31;

        for (unsigned int j = 1; j <= UINT; j++) {

            putchar(number & mask ? '1' : '0');

            number <<= 1;

            if (j % 8 == 0) printf("  ");

        }

        printf("\n");

    }
}

