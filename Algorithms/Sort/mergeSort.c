#include <stdio.h>
int ar[100];// = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int b[100];
int sz;


void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(ar[l1] <= ar[l2])
         b[i] = ar[l1++];
      else
         b[i] = ar[l2++];
   }

   while(l1 <= mid)
      b[i++] = ar[l1++];

   while(l2 <= high)
      b[i++] = ar[l2++];

   for(i = low; i <= high; i++)
      ar[i] = b[i];
}

void msort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      msort(low, mid);
      msort(mid+1, high);
      merging(low, mid, high);
   }else {
      return;
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
   printf("List before msorting\n");

   for(i = 0; i < sz; i++)
      printf("%d ", ar[i]);

   msort(0, sz-1);

   printf("\nList after msorting\n");

   for(i = 0; i < sz; i++)
      printf("%d ", ar[i]);
}
