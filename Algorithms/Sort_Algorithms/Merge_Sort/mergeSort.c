#include <stdio.h>
int ar[100];
int b[100];
int n;


void merging(int low, int mid, int high) {
   //Declare variables
   int l1, l2, i;

   //Put the element of the two smaller elements in the new array
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(ar[l1] <= ar[l2])
         b[i] = ar[l1++];
      else
         b[i] = ar[l2++];
   }

   //Finish off in case some of the elements are not put
   while(l1 <= mid)
      b[i++] = ar[l1++];

   //Finish off in case some of the elements are not put
   while(l2 <= high)
      b[i++] = ar[l2++];

   //Copy the elements of first array into the second array
   for(i = low; i <= high; i++)
      ar[i] = b[i];
}

void mergeSort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      mergeSort(low, mid);
      mergeSort(mid+1, high);
      merging(low, mid, high);
   }
   
   else 
      return;
   
}

int main() {
   
   int i;
   
   printf("Please enter the number of elements that you will be entering into the array\n");
   scanf("%d",&n);
   printf("Enter the elements into the array in an orderly fashion:\n");
   
   for ( i = 0; i < n; i++) 
     scanf("%d",&ar[i]);

   mergeSort(0, n-1);
   printf("\nList after Merge Sort\n");

   for(i = 0; i < n; i++)
      printf("%d ", ar[i]);
}
