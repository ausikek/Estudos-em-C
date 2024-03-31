#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node* next;
};

typedef struct node Node;
typedef Node* nodePtr;

int enqueue(nodePtr* head, nodePtr* tail, int value);
int dequeue(nodePtr* head, nodePtr* tail);
void printQueue(nodePtr head);


int main(void) {

    nodePtr head = NULL;
    nodePtr tail = NULL;

    int value = 0;
    int choice = 0;

    while (choice != 9) {

        printf("> ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf(">>> ");

                scanf("%d", &value);

                enqueue(&head, &tail, value);

                break;

            case 2:

                dequeue(&head, &tail);

                break;

            case 3:

                printQueue(head);

                break;

            case 9:

                break;
        }
    }


}


int enqueue(nodePtr* head, nodePtr* tail, int value) {

    nodePtr newNode = malloc(sizeof(Node));

    if (newNode == NULL) {

        printf("Out of memory");

        return 1;

    }

    if (*head == NULL && *tail == NULL) {

        newNode -> data = value;
        newNode -> next = NULL;

        *head = newNode;
        *tail = newNode;

        return 0;

    }

    newNode -> data = value;
    newNode -> next = *head;

    *head = newNode;

    return 0;

}

int dequeue(nodePtr* head, nodePtr* tail) {

    if (*head == NULL && *tail == NULL) {

        printf("Queue is empty\n");

        return 1;

    }

    if (*head == *tail) {

        nodePtr tempPtr = *head;

        *head = NULL;
        *tail = NULL;

        free(tempPtr);

        return 0;

    }

    nodePtr currentPtr = *head;

    while (currentPtr -> next != *tail) {

        currentPtr = currentPtr -> next;

    }

    nodePtr tempPtr = *tail;

    *tail = currentPtr;

    currentPtr -> next = NULL;

    free(tempPtr);

    return 0;

}


void printQueue(nodePtr head) {

    nodePtr currentPtr = head;

    while(currentPtr != NULL) {

        printf("%d -> ", currentPtr -> data);

        currentPtr = currentPtr -> next;

    }

    printf("NULL\n");

}