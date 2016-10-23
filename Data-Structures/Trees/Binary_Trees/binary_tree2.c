#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode (int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return(node);
}

void printInOrder(struct node* node) {
	if (node == NULL) 
		return;

	printInOrder(node -> left);

	printf("%d ", node -> data);

	printInOrder(node -> right);


}

void printPreOrder(struct node* node) {
	if(node == NULL)
		return;

	printf("%d ", node -> data);

	printPreOrder(node -> left);

	printPreOrder(node -> right);

}

void printPostOrder(struct node* node) {
	if(node == NULL) 
		return;

	printPostOrder(node -> left);

	printPostOrder(node -> right);

	printf("%d ", node -> data);
}

int main() {
	/* code */
	struct node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);

	printf("Preorder traversal is \n");
	printPreOrder(root);
	printf("\n");


	printf("Post Order traversal is \n");
	printPostOrder(root);
	printf("\n");

	printf("In order traversal is \n");
	printInOrder(root);
	printf("\n");

	return 0;
}