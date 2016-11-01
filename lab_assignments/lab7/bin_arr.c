#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int arr[100],count;

void inorder(int pos)
{
 int i,j;
 i = 2*pos + 1;
 if(arr[i] != 0)
 inorder(i);
 printf("%d\t",arr[pos]);

 j = 2*pos +2;
 if(arr[j] != 0)
 inorder(j);
}

void main()
{
 int i,num,choice;
 count = 0;
 for(i=0;i<100;i++)
 arr[i] = '\0';
 do
 {
  printf("\t\tMENU\n1.Insert into tree\n2.delete from tree\n3.search for an element in tree\n4.inorder traversal\n5. Print the array\n");
  printf("6.Exit\n");
  printf("\nEnter your choice: ");
  scanf("%d",&choice);

  switch(choice)
  {

  case 1:
	printf("Enter element: ");
	scanf("%d",&num);
	arr[count] = num;
	count++;
	break;

  case 2:
	printf("\nEnter the element to be deleted: ");
	scanf("%d",&num);
	for(i=0;i<count;i++)
	{
	 if(arr[i]==num)
	 {
	  while(i<count)
	  {
	   arr[i]=arr[i+1];
	   i++;
	  }
	  count--;
	  break;
	 }
	}
	if(i==count)
	 printf("Element not found!!\n\n");
	else
	 printf("Element Deleted Successfully!!\n\n");
	break;

  case 3:
	printf("\nEnter the element to be searched: ");
	scanf("%d",&num);
	for(i=0;i<count;i++)
	{
	 if(arr[i]==num)
	 {
 	  printf("\n element found!!\n");
	  break;
	 }
	}
	if(i==count)
	printf("\n element not found!\n\n");
	break;

  case 4:
	inorder(0);
	printf("\n\n");
	break;

  case 5:
	printf("\n\n");
	for(i=0;i<count;i++)
	printf("%d\t",arr[i]);
	printf("\n\n");
  }
 }while(choice != 6);
}
