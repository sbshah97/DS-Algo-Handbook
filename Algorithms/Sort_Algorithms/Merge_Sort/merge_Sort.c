#include <stdio.h>
#include <stdlib.h>

int arr[100];
int b[100];

void merge(int low, int mid, int high) {
	int l1, l2, i;

	for(i = low, l1 = low, l2 = mid + 1; l1 <= mid && l2 <= high; i++) {
		if(arr[l1] <= arr[l2]) {
			b[i] = arr[l1++];
		}
		else {
			b[i] = arr[l2++];
		}
	}

	while(l1 <= mid)
		b[i++] = arr[l1++];

	while(l2 <= high)
		b[i++] = arr[l2++];

	for(i = low; i <= high; i ++) 
		arr[i] = b[i];
}

void mergeSort(int low, int high) {
	int mid = (low + high) / 2;

	if(low < high) {
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low, mid, high);
	}
}


int main() {
	
	int i, n;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);

	for(i = 0 ; i < n ; i ++) 
		scanf("%d",&arr[i]);
	
	mergeSort(0, n-1);

	for(i = 0; i < n; i ++)
		printf("%d ", arr[i]);

	return 0;
}
