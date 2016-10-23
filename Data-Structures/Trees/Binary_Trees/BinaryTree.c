#include <stdio.h>
#include <stdlib.h>
int ar[20],count;

void inorder(int pos)
{
  int i=0,j=0;
  i=(2*pos)+1;
  if(ar[i]!=0)
    inorder(i);
  printf("\t%d",ar[pos]);
  j=(pos*2)+2;
  if(ar[j]!=0)
    inorder(j);
}

int main()
{
  int i,num,ch;
  count=0;
  for(i=0;i<20;i++)
    ar[i]=0;

  do {
    printf("###Array implementation of a binary TREE###\n1.insert an element into the TREE\n2.delete a node from the TREE\n3.dispaly the nodes in the TREE\n4.search the nodes in the TREE\n5.exit\nENTER A ValID CHOICE TO PROCEED");
    scanf("%d",&ch);
    switch (ch) {
      case 1:
        {
          printf("enter the element to be inserted:\n");
          scanf("%d",&num);
          ar[count]=num;
          count++;
        }
      break;
      case 2:
        {
          printf("enter the element to be deleted:\n");
          scanf("%d",&num);
          for(i=0;i<count;i++)
          {
            if (ar[i]==num)
            {
              count--;
              ar[i]=ar[count];
              ar[count]=0;
              /* code */
            }
          }
            /* code */
        }
      break;
      case 4:
        {
          printf("enter the element to searched:\n");
          scanf("%d",&num);
          for(i=0;i<count;i++)
          {
            if(ar[i]==num)
            {
              printf("the element is hit at index %d",(count-1));
              break;
            }
          }
          if(i==count)
          {
            printf("the element is not found");
          }
        }
      break;
      case 3:
        {
          inorder(0);
          printf("\n");
        }
      break;
      case 5:
        {
          printf("\n\nAdios!\n\n");
          exit(0);
        }
      break;
    }
    /* code */
  } while(ch!=5);
  return 0;
}
