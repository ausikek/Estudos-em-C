#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

int main(void) {

    void q8_6(void);
    void q8_7(void);
    void q8_8(void);
    void q8_9(void);

    q8_6();
    q8_7();
    q8_8();
    q8_9();
    
    return 0;
}

void q8_6(void) {


    puts(" ");

    char s[SIZE];

    fgets(s, SIZE, stdin);

    puts(" ");

    for (size_t i = 0; i < SIZE; i++) {
        
        if (s[i] == '\0') {

            break;
        
        }

        printf("%c", toupper(s[i]));

    }

    puts(" ");

    for (size_t i = 0; i < SIZE; i++) {
        
        if (s[i] == '\0') {

            break;
        
        }

        printf("%c", tolower(s[i]));

    }

    puts(" ");

}

void q8_7(void) {


    const char *num1 = "2000";
    const char *num2 = "4000";
    const char *num3 = "6000";
    const char *num4 = "8000";

    char *num1Ptr;
    char *num2Ptr;
    char *num3Ptr;
    char *num4Ptr;


    int x = strtol(num1, &num1Ptr, 0) + strtol(num2, &num2Ptr, 0) + strtol(num3, &num3Ptr, 0) + strtol(num4, &num4Ptr, 0);

    printf("%d\n", x);

}

void q8_8(void) {


    const char *num1 = "2000.2";
    const char *num2 = "4000.4";
    const char *num3 = "6000.2";
    const char *num4 = "8000.2";

    char *num1Ptr;
    char *num2Ptr;
    char *num3Ptr;
    char *num4Ptr;


    double x = strtod(num1, &num1Ptr) + strtod(num2, &num2Ptr) + strtod(num3, &num3Ptr) + strtod(num4, &num4Ptr);

    printf("%.1f\n", x);

}

void q8_9(void) {

    char s1[SIZE];
    char s2[SIZE];

    fgets(s1, SIZE, stdin);
    fgets(s2, SIZE, stdin);
    
    int x = strcmp(s1, s2);

    if (x == 0) {

        printf("They're equal");

    } else if (x > 0) {

        printf("String 1 is bigger than string 2.");

    } else {

        printf("String 2 is bigger than string 1.");

    }     
}