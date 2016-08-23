#include<stdio.h>

int main() {
	
	//Variable Declaration
	int n;
	printf("Enter number of elements in the array\n");
	scanf("%d",&n);
	int a[n+1];
	int i,k;
	int b[n+1];
	
	//Array Input
	printf("Enter %d elements in the given array\n",n);
	for(i = 0 ; i < n ; i ++)
        	scanf("%d",&a[i]);
        
    for(i = 0 ; i < n ; i ++)
        printf("%d ",a[i]);

    printf("\n");
        
    //Element position and element Input
    int x;
    printf("Enter the element to be added to the array\n");
    scanf("%d",&x);
    printf("Enter the position at which the element should be added\n");
    scanf("%d",&k);
    	
    
    for(i = n-1; i >= k-1 ; i--)
        a[i + 1] = a[i];
        
    a[k-1] = x;
    
	
	for(i = 0 ; i <= n ; i ++)
        printf("%d ",a[i]);

	return 0;
}
