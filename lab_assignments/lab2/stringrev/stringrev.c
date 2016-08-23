#include<stdio.h>
#include<string.h>
void main()
{
void reverse(char s[]);
char s[100],s1[100];

int n;
int l;
int i,j,k;
printf("Enter number of test cases: ");
scanf("%d",&n);
for(i=1;i<=n;i++) 
{
k=0;
printf("Enter string: ");
scanf("%s",s);
l=strlen(s);
for(j=l-1;j>=0;j--)
{
printf("%c",s[j]);
}
printf("\n");


}
}



