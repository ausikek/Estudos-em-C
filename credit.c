#include <stdio.h>

int main(void) {

    int number;
    float balance;
    float charge;
    float credits;
    float allowed_limit;
    float new_balance;

    while (number != -1) {

        printf("Enter account number (-1 to end): ");
        scanf("%d", &number);

        if (number != -1) {
            
            printf("Enter beggining balance: ");
            scanf("%f", &balance);

            printf("Enter total charges: ");
            scanf("%f", &charge);

            printf("Enter total credits: ");
            scanf("%f", &credits);

            printf("Enter credit limit: ");
            scanf("%f", &allowed_limit);

            printf(" \n");

            new_balance = balance + charge - credits;

            if (new_balance > allowed_limit) {

                printf("Account:        %d\n", number);
                printf("Credit limit:   %.2f\n", allowed_limit);
                printf("Balance:        %.2f\n", new_balance);
                printf("Credit Limit Exceeded\n\n");

            }
        
        } else {
            
            printf(" \n");
        
        }

    }

    return 0;
}