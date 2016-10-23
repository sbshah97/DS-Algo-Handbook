#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
	int data;
	struct node* next;
};

void printList(struct node *n) {
	while(n != NULL) {
		cout << n->data << endl;
		n = n-> next;
	}
}

int main(){
	struct node* one = NULL;
	struct node* two = NULL;
	struct node* three = NULL;

	one = (struct node*)malloc(sizeof(struct node));
	two = (struct node*)malloc(sizeof(struct node));
	three = (struct node*)malloc(sizeof(struct node));

	one->data = 1;
	one->next = two;

	two -> data = 2;
	two -> next = three;

	three -> data = 3;
	three -> next = NULL;

	printList(one);

	return 0;

}
