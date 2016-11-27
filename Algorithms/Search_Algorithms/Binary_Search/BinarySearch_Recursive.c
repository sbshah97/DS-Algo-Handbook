#include <stdio.h>
#include <stdlib.h>

struct ar {
    int ele;
    int in;
};

typedef struct ar arr;

//compare function for sorting the array of structures
int acompare(const void * a,const void * b)  {
    arr *a1=(arr*)a;
    arr *a2=(arr*)b;
   return a1->ele-a2->ele;
}

int binary_search(arr *a,int l,int h,int v) {
    
    if(l > h) {
        return -1;
    }

    int mid = (l+h) >> 1;
    
    if(a[mid].ele == v) //element found
        return mid;
    
    if(a[mid].ele < v) 
        return binary_search(a,mid+1,h,v); //search on the left half of array
    
    return binary_search(a,l,mid-1,v); //search on right half of array
}

int main() {
    
    int n,i,v;
    arr *a; //structure to store element with previous index
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    
    a=(arr*)malloc(n*sizeof(arr));
    printf("Enter array elements\n");
    for(i = 0;i < n;i ++) {
        scanf("%d",&a[i].ele);
        a[i].in=i; //store the index of original array
    }

    qsort(a,n,sizeof(arr),acompare); //sort the structure
    printf("Enter the element to be searched\n");
    scanf("%d",&v);
    int in = binary_search(a,0,n-1,v);
    
    if(in==-1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n",a[in].in+1);
    return 0;
}
