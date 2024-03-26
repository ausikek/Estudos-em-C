#include <stdio.h>


union problem {
    char c;
    short s;
    int i;
    long b;
};


int main(void) {

    union problem test;

    test.b = 5000;

    printf("%s%c\n%s%d\n%s%d\n%s%u\n", "char: ", test.c, "short: ", test.s,
    "int: ", test.i, "long: ", test.b);

    return 0;
}