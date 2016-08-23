#include<stdio.h>
void main()
{
int n,a;
int *rev,*rem,*temp;
clrscr();
printf(“Enter any number: “);
scanf(“%d”,&n);
a=n;
temp=&n;
*rev=0;
while(*temp>0)
{
*rem=*temp%10;
*temp=*temp/10;
*rev=(*rev)*10+*rem;
}
printf(“Reverse of %d is %d”,a,*rev);
getch();
}
