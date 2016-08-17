#include<stdio.h>
int main() {
	int n1,n2,i,j = 0 , k = 0;
	printf("Enter the number of elements in the two arrays\n");
	scanf("%d %d",&n1,&n2);

	int a[n1],b[n2],c[n1+n2];
	printf("Enter the elements in the first array\n");
	for(i = 0 ; i < n1 ; i ++)
		scanf("%d",&a[i]);

	printf("Enter the elements in the second array\n");
	for(i = 0 ; i < n2 ; i ++)
		scanf("%d",&b[i]);


	for(i = 0 ; i < n1 + n2 ; i ++) {
		if(a[j] <= b[k]) {
			c[i] = a[j];
			j++;
		}

		else if(a[j] >= b[k]) {
			c[i] = b[k];
			k++;
		}

	}
	int x = i;

	printf("Array after sorting\n");
	for(i = 0 ; i < n1 + n2 ; i ++)
		printf("%d ",c[i]);

	printf("\n");
	return 0;
}
