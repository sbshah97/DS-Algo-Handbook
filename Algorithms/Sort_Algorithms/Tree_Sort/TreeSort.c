#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;

void main( )
{
    struct btreenode *bt ;
    int number;
    printf("Enter number of elements in array: ");
    scanf("%d",&number);
    int arr[number];
    int i ;
    printf("\nEnter space seperated elements\n");
    for(i=0;i<number;i++)
        scanf("%d",&arr[i]);
    
    printf ( "\nArray entered is:\n") ;
    for ( i = 0 ; i <number ; i++ )
        printf ( "%d\t", arr[i] ) ;
    bt = NULL ;
    printf("\n");

    for ( i = 0 ; i < number ; i++ )
        insert ( &bt, arr[i] ) ;

    printf ( "After tree sort:\n" ) ;
    inorder ( bt ) ;

}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        printf ( "%d\t", sr -> data ) ;
        inorder ( sr -> rightchild ) ;
    }
}

