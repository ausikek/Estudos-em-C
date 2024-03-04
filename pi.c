#include <stdio.h>

int main(void) {

    unsigned int x;
    unsigned int i;
    int j = 1;
    float pi = 0;

    printf("Insert how many iterations you want: \n");
    scanf("%u", &x);

    for (i = 1; i <= x; i++) {

        if (j > 0) {
            
            pi = pi + ( (float) 4 / (float) (2*i - 1) ); 

            j = -j;

        } else {

            pi = pi - ( (float) 4 / (float) (2*i - 1) );

            j = -j;

        }

    }

    printf("%.50f", pi);

    return 0;
}