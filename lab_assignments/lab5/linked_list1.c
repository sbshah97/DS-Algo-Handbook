#include <stdio.h>
#include <stdlib.h>

//Declare 
struct List {
	int data;
	struct List *next;
};

int listLength(struct List *head) {
	struct List *current = head;
	int count = 0;

	while(current != NULL) {
		count ++;
		current = current->next;
	}
	return count;
}

void insertLinkedList (struct List **head, int data, int position) {
	int k = 1;
	struct List *p, *q, *newNode;
	newNode = (struct List*)malloc(sizeof(struct List));

	newNode -> data = data;
	p=*head;
	if(position ==1) {
		newNode->next = p;
		*head = newNode;
	}

	else {
		while((p != NULL) && (k<position)) {
			k++;
			q = p;
			p = p-> next;
		}
		q -> next = newNode;
		newNode -> next = p;
	}
}

void deleteLinkedList (struct List **head, int position) {
	int k = 1;
	struct List *p, *q, *newNode;
	
	if(*head = NULL) {
		printf("List empty\n");
		return;
	}

	if(position == 1) {
		*head = (*head) -> next;
		free(p);
		return;
	}

	else {
		while((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p-> next;
		}
		if(p == NULL)
			printf("Position does not exist");
		else {
			q->next = p->next;
			free(p);
		}
	}
}

void display(struct List **head) {
    printf("\nContents of the linked list are: \n");
    struct List *p;
	p=*head;
	if(*head = NULL) {
		printf("List empty\n");
		return;
	}
    while(p != NULL) {
        printf("%d\n", p->data);
    	p = p->next;
    }
}

int main() {
	struct List* head = NULL;

	insertLinkedList(&head, 4, 1);
	insertLinkedList(&head, 6, 1);
	display(&head);
	deleteLinkedList(&head, 1);
	display(&head);
	return 0;
}