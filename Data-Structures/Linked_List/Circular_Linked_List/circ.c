#include<stdio.h>

#include<stdlib.h>



struct node

{

 int d;

 struct node *next;

}*front=NULL,*temp=NULL,*ptr,*k;



void push()

{

 int num,pos,c=0;



 printf("\nEnter position where number has to inserted:");

 scanf("%d",&pos);



 ptr=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter data:");

  scanf("%d",&num);

  ptr->next=NULL;

  ptr->d=num;



 if(pos==1)

 {

   front=ptr;

   ptr->next=front;

  }

 else

{

  temp=front;

 while(c<pos-1)

 {

  k=temp;

  temp=temp->next;

  c++;

 }

 k->next=ptr;

 ptr->next=temp;



}



  }



void pop()

{

 int pos,c=0;





 if(front==NULL)

 {

  printf("\nUNDERFLOW!!!");

  exit(0);

 }



 else

 {

  printf("\nEnter position of node whose data is to be deleted:");

  scanf("%d",&pos);


  ptr=front;

  while(c<pos-1)

  {

   k=ptr;

   ptr=ptr->next;

   c++;

  }

   k->next=ptr->next;

   free(ptr);

   printf("\nNode at position %d is deleted",c+1);

 }

}

void display()

{

 ptr=front;

 printf("\nPrinting circular list >>>-beg and <<<-end\n");

 printf(">>>%d->",ptr->d);

 ptr=ptr->next;

 for(;ptr!=front;ptr=ptr->next)

 printf("%d->",ptr->d);

 printf("<<<");

}



void main()

{

 int c;

 char ch,t;

 

do

{

  printf("\n1.Insert \t 2.Delete \t 3.Display");

  printf("\n Enter your choice:");

  scanf("%d",&c);



  switch(c)

 {

   case 1: push(); break;

   case 2: pop(); break;

   case 3: display(); break;

   default: printf("\nEnter choice as 1,2 or 3");

 }

 printf("\nDo you want to continue(y:yes/n:no)");

 scanf("%c",&t);

 scanf("%c",&ch);



}while(ch=='y'||ch=='Y');




}
