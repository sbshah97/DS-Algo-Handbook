#include <stdio.h>
#include <stdlib.h>

int top = -1;
int n = 100;
int arr[100];

void push(int x) {
	if(overflow())
		return;
	else {
		top+=1;
		arr[top]=x;
		printf("%d",arr[top]);
	}
}

int pop() {
	if(underflow()) 
		return;
	
	else {
		top--;
		return arr[top-1];
	}
}

int underflow() {
	if(top==-1) {
		printf("Underflow has occurred\n");
		return 0;
	}
}

int overflow(){
	if(top == n) {
		printf("Overflow has occurred\n");
		return 0;
	}
}

void printStack() {
	int i;
	printf("The elements of the array are:\n");
	for(i = top; i > -1; i --) {
		printf("%d\n");
	}
}

int main() {
	int x,i;

	while(1) {

		printf("Welcome to the Stack Data Structure\n");
		printf("Enter 1 to Push\n");
		printf("Enter 2 to Pop\n");
		printf("Enter 3 to Exit\n");

		scanf("%d",&x);
		switch(x) {
			case 1:
				printf("Enter the number to push\n");
				scanf("%d",&i);
				push(i);
				break;
			case 2:
				i = pop();
				printf("%d is popped\n",i);
				break;
			case 3:
				printStack();
				break;
			case 4:
				exit(-1);
		}
	}

	return 0;
}