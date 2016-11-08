//Include header files
#include <stdio.h>
#include <stdlib.h>
 
#define size 50

//Define Stack Structure
struct stack {
   int s[size];
   int top;
} st;

//Full Stack condition 
int stfull() {
   if (st.top >= size - 1)
      return 1;
   else
      return 0;
}

//Push function
void push(int item) {
   st.top++;
   st.s[st.top] = item;
}
 
//Empty stack condition
int stempty() {
   if (st.top == -1)
      return 1;
   else
      return 0;
}
 
//Pop element from stack
int pop() {
   int item;
   item = st.s[st.top];
   st.top--;
   return (item);
}
 
//Display elements of stack
void display() {
   int i;
   if (stempty())
      printf("\nStack Is Empty!");
   else {
      for (i = st.top; i >= 0; i--)
         printf("\n%d", st.s[i]);
   }
}
 
//Mian function
int main() {
   //Variable declaration
   int item, choice;
   char ans;
   st.top = -1;
 
   printf("\n\tImplementation Of Stack");
   do {
      printf("\nMain Menu");
      printf("\n1.Push \n2.Pop \n3.Display \n4.exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
         printf("\nEnter The item to be pushed");
         scanf("%d", &item);
         if (stfull())
            printf("\nStack is Full!");
         else
            push(item);
         break;
      case 2:
         if (stempty())
            printf("\nEmpty stack!Underflow !!");
         else {
            item = pop();
            printf("\nThe popped element is %d", item);
         }
         break;
      case 3:
         display();
         break;
      case 4:
         exit(0);
      }
      printf("\nDo You want To Continue?");
   }while (1);
 
return 0;
}