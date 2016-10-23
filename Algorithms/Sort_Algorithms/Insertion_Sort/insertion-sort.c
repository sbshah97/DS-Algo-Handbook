#include<stdio.h>
int main()
{
  int i,j,sz,temp;
  printf("enter the number of elements to input:\n");
  scanf("%d",&sz);
  int ar[sz];
  printf("enter the elments:\n");
  for(i=0;i<sz;i++)
    scanf("%d",&ar[i]);
  printf("array before sorting:\n");
  for(i=0;i<sz;i++)
    printf("%d\n",ar[i]);
  for(i=1;i<sz;i++)
  {
      temp=ar[i];
      j=i-1;
      while((temp<ar[j])&&(j>=0))
      {
          ar[j+1]=ar[j];
          j=j-1;
      }
      ar[j+1]=temp;
  }
  printf("array after sorting:\n");
  for(i=0;i<sz;i++)
      printf("%d\n",ar[i]);
  return 0;
}
