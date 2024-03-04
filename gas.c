#include <stdio.h>

int main(void) {

    float miles;
    float gallons;

    miles = 0;
    gallons = 0;
    
    float average;
    float total_miles;
    float total_gallons;

    average = 0;
    total_miles = 0;
    total_gallons = 0;
    
    int counter;

    counter = 0;

    while (gallons != -1) {
        
        printf("Enter the gallons used (-1 to end): ");
        scanf("%f", &gallons);

        if (gallons == -1) {

            printf(" \n");

        } else {
            
            printf("Enter the miles driven: ");
            scanf("%f", &miles);

            average = miles / gallons;

            printf("The miles/gallon for this tank was %f\n", average);
            printf(" \n");

            counter = counter + 1;

            total_miles = total_miles + miles;
            total_gallons = total_gallons + gallons;
        }       
    }

    if (counter != 0) {

        float arithmetic_avg;
        arithmetic_avg = total_miles / total_gallons;
        
        printf("The overall average miles/galon was %f\n", arithmetic_avg);

    }

    return 0;
}