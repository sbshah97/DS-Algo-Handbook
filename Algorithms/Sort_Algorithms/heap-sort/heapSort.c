#include <stdio.h>
int ar[100];// = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int b[100];
int sz;


/* 
    This function check whether the element at ar[i] is the
    largest among both of its child or not. If not, it will
    swap the elements, so that the largest is on the root, 
    and repeat the same for it's child.
*/

void heapify(int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    int temp;
    if (l < n && ar[l] > ar[largest])
        largest = l;
    if (r < n && ar[r] > ar[largest])
        largest = r;
    if (largest != i)
    {
        temp=ar[i];
        ar[i]=ar[largest];
        ar[largest]=temp;
        heapify(n, largest);
    }
}

/*
    This function will heapify the first half of the array ar[].
    Then, it will swap the largest element with the last element
    in the array ar[] and repeat heapify.
*/

void heapSort()
{
    int temp;
    for (int i = sz / 2 - 1; i >= 0; i--)
        heapify(sz, i);
    for (int i=sz-1; i>=0; i--)
    {
        temp=ar[0];
        ar[0]=ar[i];
        ar[i]=temp;
        heapify(i, 0);
    }
}


int main() {
    int i;
    printf("Please enter the number of elements that you will be entering into the array that you want to sort:\n");
    scanf("%d", &sz);
    printf("Enter the elements into the array:\n");
    for ( i = 0; i < sz; i++)
        scanf("%d", &ar[i]);
    
    
    printf("List before sorting\n");
    for(i = 0; i < sz; i++)
       printf("%d ", ar[i]);

    heapSort();

    printf("\nList after sorting\n");
    for(i = 0; i < sz; i++)
       printf("%d ", ar[i]);
    printf("\n");
}
