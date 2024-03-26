#include <stdio.h>


int powOfTwo(int number, int power);


int main(void) {

    int num, pow = 0;

    scanf("%d %d", &num, &pow);

    printf("%d * (2 ^ %d) = %d", num, pow, powOfTwo(num, pow));

    return 0;
}

int powOfTwo(int number, int power) {

    return number <<= power;

}