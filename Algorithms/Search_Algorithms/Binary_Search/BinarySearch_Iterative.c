#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int n, int key) {
	int first = 0;
	int last = n - 1;

	while(first < last) {
		int mid = (first + last) / 2;

		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return -1;
}

int main() {
	/* code */
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n ; i ++) 
		scanf("%d",&arr[i]);

	int key;
	scanf("%d",&key);

	int x = binary_search(arr, n, key);

	if(x == -1) 
		printf("The key wasn't found in the array\n");
	else
		printf("The key was found at position %d in the array\n", x);


	return 0;
}