// vector.h
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 100

typedef struct {
	int size;
	int capacity;
	int *data;
}Vector;

// Initialising values
void vector_init(Vector *vector) {
	// Initialize size and capacity
	vector->size = 0;
	vector->capacity = VECTOR_SIZE;

	// Allocate memory for Vector->data
	vector->data = malloc(sizeof(int)*vector->capacity);
}

// Doubling the capacity of vector
void vector_double_capacity_if_full(Vector *vector) {
	if(vector->size >= vector->capacity) {
		vector->capacity *= 2;

		vector->data = malloc(sizeof(int)*vector->capacity);
	}
}

// Adding values at the end of the array
void vector_append(Vector *vector, int value) {
	// Check if maximum vector size
	vector_double_capacity_if_full(vector);

	// Add value at the end of the array
	vector->data[vector->size++] = value;
}

// Retrieving values at the array
int vector_get(Vector *vector, int index){
	if(index >= vector->size || index < 0) {
		printf("Wrong index sent! Out of bounds!");
		exit(1);
	}

	return vector->data[index];
}

// Modifying current values in the array
void vector_set(Vector *vector, int index, int value) {
	while(index > vector->size) {
		vector_append(vector, 0);
	}
	vector->data[index] = value;
}


// Use free, delete in C++
void vector_free(Vector *vector) {
	free(vector->data);
}