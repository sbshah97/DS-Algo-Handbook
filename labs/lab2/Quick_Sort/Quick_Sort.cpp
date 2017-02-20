#include <bits/stdc++.h>

int arr[10];

int part(int low, int high) {
	int pivot = arr[high];
	int temp, i = low - 1;

	for(int j = low; j <= high - 1; j ++) {
		if(arr[j] <= pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	
	return (i + 1);
}

void quick_sort(int low, int high) {
	if(low < high) {
		int partition = part(low, high);
		quick_sort(low, partition-1);
		quick_sort(partition+1, high);
	}
}

void print_arr(int n) {
	for(int i = 0; i < n; i ++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	quick_sort(0, n - 1);

	print_arr(n);

	return 0;
}