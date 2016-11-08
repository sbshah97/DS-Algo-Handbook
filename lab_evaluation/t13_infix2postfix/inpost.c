//Include header files
#include <stdio.h>
#include <stdlib.h>

//Global Variable declaration
char stack[20];
int top = -1;

//Push elements into the stack
void push(char x) {
  stack[++top] = x;
}
 
//Pop elements from the stack
char pop() {
  if(top == -1)
    return -1;
  else
    return stack[top--];
}
 
//Priority of elements
int priority(char x) {
  if(x == '(')
    return 0;
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/')
    return 2;
}
 
//Main function
int main() {
  //Variable declaration
  char exp[20];
  char *e, x;
  
  //Input data
  printf("Enter the expression :: ");
  scanf("%s",exp);
  e = exp;
  
  //Expression evaluation
  while(*e != '\0') {
    //If - Expression is number
    if(*e>=48&&*e<=57)
      printf("%c",*e);
    //If expression is opening bracket
    else if(*e == '(')
      push(*e);
    //If expression is closing bracket
    else if(*e == ')') {
      while((x = pop()) != '(')
    printf("%c", x);
    }
    //Handle according to priority
    else {
      while(priority(stack[top]) >= priority(*e))
        printf("%c",pop());
        push(*e);
    }
    e++;
  }
  
  //Print all remaining symbols at the end
  while(top != -1) {
    printf("%c",pop());
  }
  printf("\n");
  return 0;
}
