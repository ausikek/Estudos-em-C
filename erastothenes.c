#include <stdio.h>

#define SIZE 100000

int main(void) {

    int primes[SIZE];

    for (size_t i = 2; i < SIZE; i++) {

        primes[i] = 1;

    }

    for (size_t j = 2; j < SIZE; j++) {

        if (primes[j] == 1) {

            for (size_t x = j + 1; x < SIZE; x++) {

                if ( x % j == 0) {

                    primes[x] = 0;
                
                }
            }
        }
    }

    for (size_t k = 2; k < SIZE; k++) {

        if (primes[k] == 1) {

            printf("%d ", k);

        }
    }

    return 0;
}