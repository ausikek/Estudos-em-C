#include <stdio.h>

// breaks in F47 due to integer overflow :)

unsigned long long int fibonacci(unsigned int n);

int main(void) {

    unsigned int number;

    printf("%s", "Insert which Fibonacci number you want: \n");
    scanf("%u", &number);
    
    printf("%llu", fibonacci(number));

    return 0;
}

unsigned long long int fibonacci(unsigned int n) {

    int counter = 1;
    unsigned long long int result = 0;

    int m_2 = 0;
    int m_1 = 1;

    for (counter; counter <= n-1; counter++) {
        
        int m  = m_1 + m_2;
        
        result = m;

        m_2 = m_1;
        m_1 = m;

    }

    return result;

}