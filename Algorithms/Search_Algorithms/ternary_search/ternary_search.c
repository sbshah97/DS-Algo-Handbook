#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int a[10],temp,i,j,n,x,p,mid1,mid2,low,high;
printf("Enter the length of a array::\n");
scanf("%d",&n);
printf("Enter the elements in sorted order\n");
 for(i=0;i<=n;i++);
    scanf("%d",&a[i]);

printf("\nEnter a element to search in the array::\t");
scanf("%d",&x);
 
low=0;
high=n-1;
 
while(low<=high)

{
 
    mid1=(low+high)/2;
    mid2=2*mid1;
 
    if(x==a[mid1])
    {
        printf("\nElement present in the array");
        printf("\nposition is %d\n\nvalue is %d\n",mid1+1,a[mid1]);
        break;
    }
 
    else if(x<a[mid1])
        high=mid1-1;
 
 
    else if(x==a[mid2])
 
    {
        printf("\nElement present in the array");
        printf("\nposition is %d\n\nvalue is %d\n",mid2+1,a[mid2]);
        break;
    }
 
    else if(x<a[mid2])
    {
        low=mid1+1;
        high=mid2-1;
    }
 
    else
        low=mid2+1;
 
}
return 0;
}
