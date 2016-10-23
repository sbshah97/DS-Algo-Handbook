#include <stdio.h>
#include <stdlib.h>
//Stack Declaration - Initialise Condition
struct arrayStack {
	int top;
	int capacity;
	int *array;
};


//Create Stack - Create a stack with required conditions 
struct arrayStack *createStack(int capacity) {
	struct arrayStack *S = (struct arrayStack*) malloc(sizeof(struct arrayStack));
	S->capacity = capacity;
	S->top = -1;
	S->array = malloc (S->capacity * sizeof(int));
	return S;
}

int isStackEmpty(struct arrayStack *S) {
	return (S->top == -1); //If the condition is true then 1 is return else 0 is returned
}

int isFullStack(struct arrayStack *S) {
	return (S->top == S->capacity - 1); //If the condition is true then 1 else 0 is returned
}

void Push(struct arrayStack* S, int data) {
	if(isFullStack(S)) 
		printf("Stack overflow!");
	else 
		S->array[++S->top] = data; //Data Variable is added to the top of the Stack
}

int Pop(struct arrayStack *S) {
	if(isStackEmpty(S)) {
		printf("Empty Stack");
		return 0;
	}
	else
		return (S->array[S->top--]); //Data Variable is returned 
}

int main() {

	struct arrayStack* S =  createStack(100);
	//arrayStack *S;
	Push(S, 5);
	Push(S, 10);
	
	int x = Pop(S);
	printf("%d\n",x);
	return 0;
} 