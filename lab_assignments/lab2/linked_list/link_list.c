#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

void print(struct node *x)
{
	while (x != NULL) {
		printf("%d ", x->data);
		x = x->next;
	}
	printf("\n");
}

int main() {
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *three = NULL;

	one = (struct node*)malloc(sizeof(struct node));
        two = (struct node*)malloc(sizeof(struct node));
	three = (struct node*)malloc(sizeof(struct node));

	one -> data = 1;
	one -> next = two;

	two -> data = 2;
	two -> next = three;

	three -> data = 3;
	three -> next = NULL;

	print(one);

	return 0;
}
