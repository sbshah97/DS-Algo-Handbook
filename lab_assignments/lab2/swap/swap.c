#include<stdio.h>
void main()
{
void swap1(int a, int b);
void swap2(int *a1, int *b1);
int a,b;
printf("Enter 2 numbers: ");
scanf("%d%d",&a,&b);
//call by value
swap1(a,b);
printf("After call by value, a and b are: %d and %d\n",a,b);
//call by reference
int *a1=&a;
int *b1=&b;
swap2(a1,b1);
printf("After call by reference, a and b are: %d and %d\n",a,b);
}//main
void swap1(int a, int b)
{
int temp=a;
a=b;
b=temp;
}
void swap2(int *a1, int *b1)
{
int temp;
temp=*a1;
*a1=*b1;
*b1=temp;
}//swap2
