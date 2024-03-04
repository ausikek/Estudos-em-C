#include <stdio.h>

void main_recursive();

int main() {
    main_recursive();
    return 0;
}

void main_recursive() {
    static int count = 1;
    printf("Count: %d\n", count++);
    main();  // Recursive call to main
}
