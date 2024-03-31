#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node Node;
typedef Node* nodePtr;


int push(nodePtr* head, int value);
int pop(nodePtr* head);
void printList(nodePtr head);


int main(void) {

    nodePtr headPtr = NULL;

    int value = 0;
    int choice = -1;

    while (choice != 0) {

        printf(">> ");

        scanf("%d", &choice);

        switch (choice) {
        
        case 1:

            printf(">>> ");

            scanf("%d", &value);
            
            push(&headPtr, value);

            break;
        
        case 2:

            printList(headPtr);

            break;

        case 3:

            pop(&headPtr);

            break;

        case 0:

            break;

        default:

            printf("Invalid choice\n");

            break;
        
        }
    }
}


int push(nodePtr* head, int value) {

    nodePtr newPtr = malloc(sizeof(Node));

    if (newPtr == NULL) {

        printf("Not enough memory allocated");

        return 1;

    }

    if (*head == NULL) {

        newPtr -> data = value;
        newPtr -> next = NULL;
        
        *head = newPtr;

        return 0;

    }

    newPtr -> data = value;
    newPtr -> next = *head;

    *head = newPtr;

    return 0;

}


int pop(nodePtr* head) {

    if (*head == NULL) {

        printf("Stack is empty\n");

        return 1;

    }

    nodePtr tempPtr = *head;

    (*head) = (*head) -> next;

    free(tempPtr);

    return 0;

}


void printList(nodePtr head) {

    nodePtr currentPtr = head;

    while (currentPtr != NULL) {

        printf("%d -> ", currentPtr -> data);

        currentPtr = currentPtr -> next;

    }

    printf("NULL\n");

}