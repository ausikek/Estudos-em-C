#include <stdio.h>

typedef union {  
    
    float f;
    double d;
    long double x;

} floatingPoints;

int main(void) {

    floatingPoints test;

    test.x = 2432423432144.5;

    printf("%s%f\n %s%lf\n %s%Lf\n", "Float: ", test.f, "Double: ", test.d, "Long Double: ", test.x);

    return 0;
}