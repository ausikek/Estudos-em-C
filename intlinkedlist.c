#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    int data;
    struct node* nextPtr;
};

typedef struct node Node;
typedef Node* Ptr;


int insert(Ptr *head, int number);

int delete(Ptr *head, int number);

int isEmpty(Ptr head);

void printList(Ptr currentPtr);

void instructions(void);


int main(void) {

    Ptr startPtr = NULL;
    int num = 0;

    instructions();

    printf("%s", ">>> ");

    unsigned int choice = 0;

    scanf("%u", &choice);

    while (choice != 3) {

        switch (choice) {
            case 1:
                printf("%s", "Enter a number: ");
                scanf("\n%d", &num);
                insert(&startPtr, num);
                printList(startPtr);

                break;
            case 2:
                if (!isEmpty(startPtr)) {

                    printf("%s", "Enter character to be deleted: ");
                    scanf("\n%d", &num);

                    if (delete(&startPtr, num)) {

                        printf("%d deleted.\n", num);
                        printList(startPtr);

                    } else {

                        printf("%d not found.\n", num);

                    }

                }

                else {

                    printf("List is empty. \n\n");

                }

                break;

            default:
                printf("Invalid Choice\n\n");
                instructions();

                break;
        }

        printf("%s", ">>> ");
        scanf("%u", &choice);

    }

    printf("End of run.\n");

    return 0;
}


int insert(Ptr *head, int number) {

    Ptr newPtr = malloc(sizeof(Node));

    if (newPtr != NULL) {

        newPtr -> data = number;
        newPtr -> nextPtr = NULL;

        Ptr previousPtr = NULL;
        Ptr currentPtr = *head;

        while (currentPtr != NULL && number > currentPtr -> data) {

            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;
        
        }

        if (previousPtr == NULL) {

            newPtr -> nextPtr = *head;
            *head = newPtr;

        } else {

            previousPtr -> nextPtr = newPtr;
            newPtr -> nextPtr = currentPtr;

        }

        return 0;

    } else {

        printf("Not enough memory allocated");

        return 1;
    
    }
}


int delete(Ptr *head, int number) {

    if (number == (*head) -> data) {

        Ptr tempPtr = *head;
        *head = (*head) -> nextPtr;
        free(tempPtr);

        return number;

    } else {

        Ptr previousPtr = *head;
        Ptr currentPtr = (*head) -> nextPtr;

        while (currentPtr != NULL && currentPtr -> data != number) {

            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;
        
        }

        if (currentPtr != NULL) {

            Ptr tempPtr = currentPtr;
            previousPtr -> nextPtr = currentPtr -> nextPtr;
            free(tempPtr);

            return number;

        }
    }

    return false;

}


int isEmpty(Ptr head) {

    return head == NULL;

}


void printList(Ptr currentPtr) {

    if (isEmpty(currentPtr)) {

        printf("Empty List\n");
    
    } else {
        
        printf("The list is:\n");

        while (currentPtr != NULL) {

            printf("%d --> ", currentPtr -> data);
            
            currentPtr = currentPtr -> nextPtr;

        }

        printf("NULL\n");

    }
}


void instructions(void) {

    printf("%s\n%s\n%s\n%s", "Enter your choice: ", "   1 to insert a number into the list",
           "   2 to delete a number from the list", "   3 to quit.\n");

}

