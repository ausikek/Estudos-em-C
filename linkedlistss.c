#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* next;
};


typedef struct node Node;
typedef Node* NodePtr;


void insert(NodePtr* head, int value);

void delete(NodePtr* head, int value);

void sort(NodePtr* head);

void printlist(NodePtr head);

void selector(NodePtr head);


int main(void) {

	NodePtr head = NULL;

	selector(head);

	return 0;

}


void insert(NodePtr* head, int value) {

	NodePtr newNode = malloc(sizeof(Node));

	if (newNode == NULL) {

		printf("get fucked no memory 4 u");

		exit(1);

	}

	newNode -> next = NULL;
	newNode -> data = value;

	if (*head == NULL) {

		*head = newNode;
		
		return;

	}

	NodePtr currentPtr = *head;

	while (currentPtr->next != NULL) {

		currentPtr = currentPtr -> next;

	}

	currentPtr -> next = newNode;

}


void delete(NodePtr* head, int value) {

	if (*head == NULL) {

		printf("List is empty\n");
		
		return;

	}

	NodePtr currentPtr = *head;
	
	while (currentPtr -> data != value && currentPtr -> next != NULL) {

		currentPtr = currentPtr -> next;

	}

	if (currentPtr -> data != value) {

		printf("Item is not in the list\n");

		return;

	}

	if ((*head) -> data == value && *head != NULL) {

		NodePtr tempPtr = *head;

		(*head) = (*head) -> next;

		free(tempPtr);

	return;

	} else { 

		NodePtr previousPtr = NULL;
		currentPtr = *head;

		while (currentPtr -> data != value && currentPtr != NULL) {

			previousPtr = currentPtr;
			currentPtr = currentPtr -> next;

		}

		if (currentPtr != NULL) {

			NodePtr tempPtr = currentPtr;

			previousPtr -> next = currentPtr -> next;

			free(tempPtr);

			return;
		
		}
	}

	printf("Not found");
}


void sort(NodePtr* head) {

	NodePtr currentPtr = *head;
	NodePtr nextPtr = currentPtr -> next;

	int isSwap = 0;

	if (currentPtr == NULL) {

		printf("No elements to be sorted\n");

		return;

	}

	int elements = 1;

	while (currentPtr -> next != NULL) {

		elements++;	

		currentPtr = currentPtr -> next;

	}

	currentPtr = *head;

	for (size_t i = 1; i < elements; i++) {

		while (currentPtr -> next != NULL) {

			if (currentPtr -> data > nextPtr -> data) {

				int hold = currentPtr -> data;
				currentPtr -> data = nextPtr -> data;
				nextPtr -> data = hold;

				isSwap = 1;

			}

			currentPtr = currentPtr -> next;
			nextPtr = nextPtr -> next;
		} 

		currentPtr = *head;
		nextPtr = currentPtr -> next;

		if (isSwap == 0) {

		printf("The list is already sorted.\n");

		return;

		}
	}
}


void printlist(NodePtr head) {

	NodePtr tempPtr = head;

	while (tempPtr != NULL) {

		printf("%d -> ", tempPtr -> data);

		tempPtr = tempPtr -> next;

	}

	printf("NULL\n");

}


void selector(NodePtr head) {

	int choice = 0;

	int value = 0;

	int sentinel = 1;

	printf("%s\n%s\n%s\n%s\n%s\n",
	"Choose 1 to insert",
	"Choose 2 to delete",
	"Choose 3 to sort",
	"Choose 4 to print",
	"Choose 5 to exit");

	while (sentinel) {

		printf("> ");

		scanf("%d", &choice);

		switch (choice) {

			case 1:

				printf("Input a value to be stored: ");

				scanf("%d", &value);

				insert(&head, value);

				break;

			case 2:

				printf("Input a value to be deleted: ");

				scanf("%d", &value);

				delete(&head, value);

				break;

			case 3:

				sort(&head);

				break;

			case 4:

				printlist(head);

				break;

			case 5:

				sentinel = 0;

				break;

			default:
				
				printf("Choose a valid option\n");
				
				break;
		
		}
	}
}