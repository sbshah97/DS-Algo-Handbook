#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int a[MAX];
int front = -1;
int rear = -1;

void enqueue(int i) {
	if (front == MAX) {
		printf("Queue is full.\n");
		return ;
	}

	else if (front == -1 && rear == -1) {
		front += 1;
		rear += 1;
		a[rear] = i;
	}

	else {
		rear += 1;
		a[rear] = i;
	}

	printQueue();
}

void dequeue () {
	if(front == -1 || front == rear) {
		printf("Queue is empty.\n");
		return ;
	}

	else {
		front += 1;
	}

	printQueue();
}

int top() {
	return a[front];
}

void printQueue() {
	int i;
	printf("The Queue now looks like this:\n");
	for(i = front; i <= rear; i ++)
		printf("%d\n",a[i]);
}

int main() {
	int n;
	int i;

	printf("Welcome to the Queue Data Structure\n");

	while(1) {
		
		printf("Select one of the following operations:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Top\n");
		printf("4. Print Queue")
		printf("5. Exit\n");

		printf("Enter the option you want\n");
		scanf("%d",&n);
		switch(n) {
			case 1:
				scanf("%d",&i);
				enqueue(i);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				i = top();
				printf("%d\n",i);
				break;
			case 5:
				exit(-1);
			case 4:
				printQueue();
				break;
			default:
				printf("Entered the wrong option\n");
		}
	}
	return 0;
}

//