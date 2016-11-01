#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *left, *right;
};
 
struct node *newNode(int item) {
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void modifyBSTUtil(struct node *root, int *sum) {
    if (root == NULL)  return;
 
    modifyBSTUtil(root->right, sum);
 
    *sum = *sum + root->data;
    root->data = *sum;
 
    modifyBSTUtil(root->left, sum);
}
 
void modifyBST(struct node *root) {
    int sum = 0;
    modifyBSTUtil(root, &sum);
}
 
void inorder(struct node *root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int data) {
    if (node == NULL) 
    	return newNode(data);
 
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    return node;
}
 
// Driver Program to test above functions
int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    modifyBST(root);
 
    inorder(root);
 
    return 0;
}