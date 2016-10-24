#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

struct node {
  int key, height;
  struct node *left, *right;
};

int height(struct node *n) {
  return (n == NULL) ? 0 : n->height;
}

void preOrder(struct node *n) {
  if (n == NULL)
    return;

  printf("%d ", n->key);
  preOrder(n->left);
  preOrder(n->right);
}

void inOrder(struct node *n) {
  if (n == NULL)
    return;

  inOrder(n->left);
  printf("%d ", n->key);
  inOrder(n->right);
}

void postOrder(struct node *n) {
  if (n == NULL)
    return;

  postOrder(n->left);
  postOrder(n->right);
  printf("%d ", n->key);
}

struct node *rotateRight(struct node *y) {
  struct node *x = y->left;
  struct node *T2 = x->right;

  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

struct node *rotateLeft(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) { 
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;

    return n;
  }

  if (key < node->key) 
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  node->height = max(height(node->left), height(node->right)) + 1;
  
  int balance = (node == NULL) ? 0 : height(node->left) - height(node->right);

  if (balance > 1 && key < node->left->key) {
    return rotateRight(node);
  } else if (balance < -1 && key > node->right->key) {
    return rotateLeft(node);
  } else if (balance > 1 && key > node->left->key) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  } else if (balance < -1 && key < node->right->key) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  return node;
}

int main() {
  int n, elem;
  struct node *root = NULL;

  printf("Enter the number of elements to input:\n");
  scanf("%d", &n);

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &elem);
    root = insert(root, elem);
  }

  printf("\n");
  printf("Pre-order:\n");
  preOrder(root);
  printf("\n");

  printf("In-order:\n");
  inOrder(root);
  printf("\n");

  printf("Post-order:\n");
  postOrder(root);
  printf("\n");

  return 0;
}
