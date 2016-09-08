#include <stdio.h>
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
  for(i=0;i<sz-1;i++)
  {
    for(j=0;j<sz-1-i;j++)
    {
      if(ar[j]>ar[j+1])
      {
        temp=ar[j];
        ar[j]=ar[j+1];
        ar[j+1]=temp;
      }
    }
  }
  printf("array after sorting:\n");
  for(i=0;i<sz;i++)
    printf("%d\n",ar[i]);
}
