#include<stdio.h>
#include<string.h>
void main()
{
int n;
int key;
int flag=0;
struct stu
{
char s[100];
int rollno;
float cgpa;
}a[100];
printf("Enter number of records: ");
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
{
printf("Enter name, roll number and cgpa: ");
scanf("%s%d%f",a[i].s,&a[i].rollno,&a[i].cgpa);
}
printf("Enter roll number of student: ");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i].rollno==key)
{
flag=1;
printf("Record found!\nName:%s\nCGPA=%f\n",a[i].s,a[i].cgpa);
}
}
if(flag==0)
printf("Not found\n");
}

