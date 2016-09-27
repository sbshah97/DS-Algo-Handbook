#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int l, int r){
	if(l < r) {
		//Same as l + r /2
		int m = l + (r - l) / 2;

		//Sort first and second halves
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Create temporary arrays
	int L[n1], R[n2];

	//Copy data to temp arrays L[] and R[]
	for(i = 0; i < n1; i ++)
		L[i] = arr[l + i];
	for(j = 0 ; j < n1; j ++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

int main() {

	int n,i;
	scanf("%d",&n);
	int arr[n];

	for(i = 0; i < n; i ++) {
		scanf("%d",&arr[i]);
	}

	merge_sort(arr, 0, n - 1);

	for( i = 0; i < n; i ++)
		printf("%d ",arr[i]);

	return 0;
}