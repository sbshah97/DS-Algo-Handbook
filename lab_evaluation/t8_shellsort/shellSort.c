//Include header files
#include <stdio.h>
#include <stdlib.h>

//Global variable declaration
int ar[100];
int b[100];
int sz;

//Shell Sort function
void shellSort() {
  //Variable Declaration
  int inner, outer;
  int valueToInsert;
  int interval = 1;
  int elements = sz;

  
  while(interval <= elements/3) {
    interval = interval*3 +1;
  }

  while(interval > 0) {
    for(outer = interval; outer < elements; outer++) {
      valueToInsert = ar[outer];
      inner = outer;
      while(inner > interval -1 && ar[inner - interval] >= valueToInsert) {
        ar[inner] = ar[inner - interval];
        inner -=interval;
      }
      ar[inner] = valueToInsert;
    }
    interval = (interval -1) /3;
  }
}

//Main function
int main() {
  //Variable Declaration
  int i;
  int gap;
  
  //Input data
  printf("Enter the number of elements into the array:\n");
  scanf("%d",&sz);
  printf("Enter the elements into the array\n");
  for ( i = 0; i < sz; i++) {
    scanf("%d",&ar[i]);
  }
  
  //Call Shell SOrt function
  shellSort();

  //List after sorting
  printf("\nList after sorting\n");
  for(i = 0; i < sz; i++)
    printf("%d ", ar[i]);
}
