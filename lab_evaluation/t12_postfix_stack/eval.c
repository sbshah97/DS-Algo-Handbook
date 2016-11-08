//Include header files
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Global Variable declaration
int top=-1;

//Main function
int main() {
  //Variable declaration
  int data;
  char s[100];
  int s1[100];
  int ans;
  
  //Function Declaration
  void push(int s[],int x);
  int pop(int s[], char c);
  
  //Take input 
  printf("Enter expression with single digit numbers only: ");
  scanf("%s",s);
  printf("Entered expression is %s\n",s);
  int n=strlen(s);
  int i=0;
  
  while(i<n) {
    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
      ans=pop(s1,s[i]);
      push(s1,ans);
    }
    else if(s[i]>=48&&s[i]<=57) {
      data=s[i]-48;
      printf("%d\n",data);
      push(s1,data);
    }
    i++;
  }

  printf("Answer is: %d\n", ans);
  return 0;
}

//Push Function
void push(int s1[], int x) {
  top=top+1;
  s1[top]=x;
}	

//Pop Function
int pop(int s1[], char c) {
  int n2=s1[top];
  top--;
  int n1=s1[top];
  top--;
  if(c=='+')
    return (n1+n2);
  else if(c=='-')
    return (n2-n1);
  else if(c=='*')
    return(n1*n2);
  else 
    return(n1/n2);
}


