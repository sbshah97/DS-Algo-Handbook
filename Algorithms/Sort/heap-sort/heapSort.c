#include <stdio.h>
int ar[100];// = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int b[100];
int sz;


void heapify(int ar[], int n, int i)
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
        heapify(ar, n, largest);
    }
}

void heapSort(int ar[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);
        for (int i=n-1; i>=0; i--)
    {
        temp=ar[0];
        ar[0]=ar[i];
        ar[i]=temp;
        heapify(ar, i, 0);
    }
}


int main() {
 int i;
 printf("please enter th enumber of elements that you eill be entering into the array that you will provide to be msorted:\n");
 scanf("%d",&sz);
 printf("enter the elements into the array in an orderly fashion:\n");
 for ( i = 0; i < sz; i++)
 {
   scanf("%d",&ar[i]);
 }
 printf("List before isorting\n");

 for(i = 0; i < sz; i++)
    printf("%d ", ar[i]);

 heapSort(ar,sz);

 printf("\nList after isorting\n");

 for(i = 0; i < sz; i++)
    printf("%d ", ar[i]);
}
