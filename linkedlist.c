#include <stdio.h>
#include <stdlib.h>


struct node {
    char data;
    struct node* nextPtr;
};


typedef struct node ListNode;
typedef  ListNode* ListNodePtr;


void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);


int main(void) {

    ListNodePtr startPtr = NULL;
    char item = '0';

    instructions();

    printf("%s", ">>> ");
    unsigned  int choice = 0;
    scanf("%u", &choice);

    while (choice != 3) {

        switch (choice) {
            case 1:
                printf("%s", "Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item);
                printList(startPtr);

                break;
            case 2:
                if (!isEmpty(startPtr)) {

                    printf("%s", "Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    if (delete(&startPtr, item)) {

                        printf("%c deleted.\n", item);
                        printList(startPtr);

                    } else {

                        printf("%c not found.\n", item);

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

}

void instructions(void) {

    printf("%s\n%s\n%s\n%s", "Enter your choice: ", "   1 to insert an element into the list",
           "   2 to delete an element from the list", "   3 to quit.\n");

}

void insert(ListNodePtr *sPtr, char value) {

    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {

        newPtr -> data = value;
        newPtr -> nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr  currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr -> data) {

            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;

        }

        if (previousPtr == NULL) {

            newPtr -> nextPtr = *sPtr;
            *sPtr = newPtr;

        } else {

            previousPtr -> nextPtr = newPtr;
            newPtr -> nextPtr = currentPtr;

        }
    
    } else {

        printf("%c not inserted. Not enough memory available.\n", value);

    }
}

char delete(ListNodePtr *sPtr, char value) {

    if (value == (*sPtr) -> data) {

        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr) -> nextPtr;
        free(tempPtr);

        return value;

    } else {

        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr) -> nextPtr;


        while (currentPtr != NULL && currentPtr -> data != value) {

            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;

        }

        if (currentPtr != NULL) {

            ListNodePtr tempPtr = currentPtr;
            previousPtr -> nextPtr = currentPtr -> nextPtr;
            free(tempPtr);

            return value;
        }
    }

    return '\0';

}

int isEmpty(ListNodePtr sPtr) {

    return sPtr == NULL;

}

void printList(ListNodePtr currentPtr) {

    if (isEmpty(currentPtr)) {

        printf("List is empty\n");

    } else {

        printf("The list is:\n");

        while (currentPtr != NULL) {

            printf("%c --> ", currentPtr -> data);
            currentPtr = currentPtr -> nextPtr;

        }

        printf("NULL\n");

    }
}