#include <stdio.h>
int ar[100];// = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int b[100];
int sz;


void shellSort()
{
   int inner, outer;
   int valueToInsert;
   int interval = 1;
   int elements = sz;

   while(interval <= elements/3) {
      interval = interval*3 +1;
   }

   while(interval > 0)
   {
     for(outer = interval; outer < elements; outer++)
     {
         valueToInsert = ar[outer];
         inner = outer;

         while(inner > interval -1 && ar[inner - interval]
            >= valueToInsert)
          {
            ar[inner] = ar[inner - interval];
            inner -=interval;
           }

         ar[inner] = valueToInsert;
      }

      interval = (interval -1) /3;
     }
}



  int main() {
   int i;
   int gap;
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

    shellSort();

    printf("\nList after isorting\n");

   for(i = 0; i < sz; i++)
      printf("%d ", ar[i]);
}
