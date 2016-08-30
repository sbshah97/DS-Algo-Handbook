#include <stdio.h>
#include <stdlib.h>

int rear=-1;
int front=-1;
int queue_array[50];

void insert(int n) {
	int add_item;
	
	if(rear==n-1)
		printf("Queue Overflow\n");
	
	else {
 		if(front==-1)
 		front=0;
 		printf("Enter the element to be inserted in queue: ");
 		scanf("%d",&add_item);
 		rear++;
 		queue_array[rear]=add_item;
	}
}

void del(int n) {
	if(front==-1||front>rear) {
		printf("Queue underflow\n");
		return;
	}

	else {
		printf("Element deleted from queue is: %d\n",queue_array[front]);
		front=front+1;
	}
}

void display(int n) {
	int i;
	if(front==-1)
	printf("Queue is empty\n");

	else {
 		printf("Queue is:\n");
 		for(i = front ; i <= rear ; i++)
 			printf("%d\t",queue_array[i]);
 		printf("\n");
	}
}

void main() {
 	int o;
 	char ans;
 	int n,ch;
 	printf("Enter the no of elements in queue: ");
 	scanf("%d",&n);
 	if(n>50) {
  		printf("Enter less than 50.\n");
  		exit(0);
 	}

 	do {
 		printf("\n\t\tMENU\n");
 		printf("1. INSERT Element into Queue\n2. DELETE Element from Queue\n3. DISPLAY Elements of Queue\n4. Quit\n");
 		printf("Enter your choice: ");
 		scanf("%d",&ch);
 
 	switch(ch) {
  		case 1:
 	 		insert(n);
	 		break;
  		case 2:
	 		del(n);
	 		break;
  		case 3:
	 		display(n);
	 		break;
  		case 4:
	 		exit(0);
	 		break;
  		default:
	 		printf("Wrong choice\n");
 		}
 	printf("To continue press y...");
 	scanf("%d",&o);
 	scanf("%c",&ans);
 	}while(ans=='y');
}

