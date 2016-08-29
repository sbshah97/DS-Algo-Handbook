#include <stdio.h>
#include <stdlib.h>

struct arrayQueue {
	int front,rear;
	int capacity;
	int *array;
};

int data;

struct arrayQueue *createQueue(int size) {
	struct arrayQueue *Q = malloc(sizeof(struct arrayQueue));
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array=malloc(Q->capacity * sizeof(int));
}

int queueEmpty(struct arrayQueue *Q) { 
	return (Q->front == -1);
}

int queueFull(struct arrayQueue *Q) {
	return ((Q->rear+1) % Q->capacity == Q -> front);
}

int queueSize(struct arrayQueue *Q) {
	return (Q->capacity - Q->front + Q->rear +1) % Q->capacity;	
}

void enQueue(struct arrayQueue *Q, int data) {
	if(queueFull(Q))
		printf("Queue Overflow!");
	else {
		Q->rear = (Q->rear+1) % Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front == -1)
			Q->front = Q->rear;
	}
}

int deQueue(struct arrayQueue *Q) {
	if(queueEmpty(Q))
		printf("Stack Underflow!");

	else{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front = Q -> rear = -1;
		else
			Q-> front = (Q -> front + 1)% Q -> capacity;
	}
	return data;
}

int main() {
	struct arrayQueue *Q = createQueue(100);
	enQueue(Q, 100);
	int x = deQueue(Q);
	printf("\n%d\n",x);
}