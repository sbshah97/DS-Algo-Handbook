//Include header files
#include <stdio.h>
#include <stdlib.h>

//Global variable declaration
int front,rear;
int cq[10];

//Queue Function
void add(int item, int n) {
  if(front ==(rear+1)%n) {
    printf("\n\nCIRCULAR QUEUE IS OVERFLOW");
  }
 else {
  if(front==-1)
    front=rear=0;
  else
    rear=(rear+1)%n;
    cq[rear]=item;
    printf("\n\nRear = %d,Front = %d ",rear,front);
  }
}

//Dequeue Operation
void del(int n) {
  int a;
  if(front == -1) 
    printf("\n\nCIRCULAR QUEUE IS UNDERFLOW");
  
  else {
    a=cq[front];
    cq[front]=0;

    if(front==rear)
      front=rear=-1;

    else
      front = (front+1)%n;
  printf("\n\nDELETED ELEMENT FROM QUEUE IS : %d ",a);
  printf("\n\nRear = %d    Front = %d ",rear,front);
  }
}

//Display elements of Queue
void display(int n) {
  
  if(front == -1)
    printf("\n\nCircular queue is underflow!!");
  
  else {
    int i;
    for(i=0;i<n;i++)
      printf("%d\t",cq[i]);
  }
}

//Main function
int main() {
  //Variable declaration
  int ch,i,num,n;
  front = -1;
  rear = -1;
  //Input data
  printf("\t\t\tProgram for Circular Queue demonstration through array");
  printf("\n\nEnter the size of the circular queue: ");
  scanf("%d",&n);
  
  //Queue Operations
  while(1) {
    printf("\nMAIN MENU\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    switch(ch) {
      case 1:
      printf("\n\nENTER THE QUEUE ELEMENT: ");
      scanf("%d",&num);
      add(num,n);
      break;
      case 2:
      del(n);
      break;
      case 3:
      display(n);
      break;
      case 4:
      exit(0);
      default: 
      printf("\n\nInvalid Choice. ");
    }
  }
  return 0;
}
