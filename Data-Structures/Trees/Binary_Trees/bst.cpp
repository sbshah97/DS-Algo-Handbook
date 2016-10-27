#include<iostream>

using namespace std;

struct node
{
	node *left;
	node *right;
	int val;
};

node *root=NULL;

int isempty() 
{
	return(root==NULL);
}
struct node* insert_node(int val)
{
     node* p = new node;
     p->val = val;
     p->left = NULL;
     p->right = NULL;
 
     return(p);
}

void inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->val<<" ";
		inorder(ptr->right);
	}
}

void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->val<<" ";
	}
}

void preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		cout<<ptr->val<<" ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int main()
{
	node *root = insert_node(10);
    root->left = insert_node(20);
    root->right = insert_node(30);
    root->left->left = insert_node(40);
    root->left->right = insert_node(50);

	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	
return(0);

}