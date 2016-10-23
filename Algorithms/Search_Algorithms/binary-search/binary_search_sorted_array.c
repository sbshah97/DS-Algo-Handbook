#include<stdio.h>
#include<stdlib.h>
int binary_search(int *a,int l,int h,int v)
{
    if(l>h)
    {
        return -1;
    }
    int mid=(l+h)>>1;
    if(a[mid]==v) //element found
        return mid;
    if(a[mid]<v)
    {
        return binary_search(a,mid+1,h,v); //search on the left half of array
    }
    return binary_search(a,l,mid-1,v); //search on right half of array
}
int main()
{
    int n,i,v,*a;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&v);
    int in=binary_search(a,0,n-1,v);
    if(in==-1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n",in+1);
    return 0;
}
