#include<stdio.h>

int main() {
	//Variable declaration
	int n;
	printf("\nEnter the number of elements\n");
	scanf("%d",&n);
	int a[n];

	int key,i;

	//Input elements in the list
	printf("Enter the elements\n");
	for(i = 0 ; i < n ; i ++)
		scanf("%d",&a[i]);

	//Input search element
	printf("Enter the value of the key\n");
	scanf("%d",&key);

	int first, last, mid;
	first = 0;
	last = n-1;

	while(first < last){
		mid = (first + last)/2 ;

		if(a[mid] == key) {
			printf("Key = %d found at position %d\n",key, mid+1);
			return 0;
		}

		else if(a[mid] > key)
			last = mid - 1;

		else if(a[mid] < key)
			first = mid + 1;
	}

	return 0;
}
