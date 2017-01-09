#include <stdio.h>
#include <stdlib.h>

int A[100000];
int B[100000];

void merging(int low, int mid, int high) {
	int i, j, k;

	for(i = low, j = low, k = mid + 1 ; j <= mid && k <= high; i++) {
		if(A[j] <= A[k])
			B[i] = A[j++];
		else
			B[i] = A[k++];
	}

	while(j <= mid)
		B[i++] = A[j++];

	while(k <= mid)
		B[i++] = A[k++];

	for(i = low; i <= high; i ++)
		A[i] = B[i];
}

void mergeSort(int low, int high) {
	int mid;

	if(low < high) {
		mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merging(low, mid, high);
	}

	else 
		return;
}


int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) 
		scanf("%d",&A[i]);

	mergeSort(0, n-1);

	for(int i = 0; i < n; i ++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}