#include <stdio.h>
//#include <conio.h>
//#include <alloc.h>
#include <stdlib.h>

struct btreenode
{
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
} ;

void insert(struct btreenode **, int);
void inorder(struct btreenode *);

int main()
{
    struct btreenode *bt ;
    int i,n=10;
    int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ; // comment it if input given by user

    /*scanf("%d",&n);       // for input is given by user
    for(i=0;i<n;i++)
	scanf("%d",&arr[i]);*/

    bt = NULL;

    printf("Binary tree sort.\n");

    printf("\nArray:\n");
    for(i = 0;i<n;i++)
        printf ("%d\t",arr[i]) ;

    for (i=0;i<n;i++)
        insert(&bt,arr[i]);

    printf("\nIn-order traversal of binary tree:\n");
    inorder(bt);
    printf("\n");
    return 0;
}

void insert ( struct btreenode **sr, int num )
{
    if (*sr==NULL)
    {
        *sr = malloc (sizeof(struct btreenode)) ;

        (*sr) -> leftchild = NULL ;
        (*sr) -> data = num ;
        (*sr) -> rightchild = NULL ;
    }
    else
    {
        if (num<(*sr)->data)
            insert (&((*sr)->leftchild),num) ;
        else
            insert (&((*sr)->rightchild),num) ;
    }
}

void inorder (struct btreenode *sr)
{
    if ( sr != NULL )
    {
        inorder(sr->leftchild) ;
        printf ("%d\t",sr->data) ;
        inorder(sr->rightchild) ;
    }
}
