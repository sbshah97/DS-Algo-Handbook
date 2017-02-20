#include <bits/stdc++.h>

int count = 0;

void merge(int arr[], int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int left_arr[n1];
	int right_arr[n2];

	for(int i = 0 ; i < n1; i ++)
		left_arr[i] = arr[i];

	for(int i = 0; i < n2; i ++)
		right_arr[i] = arr[n1+i];


	int i = 0, j = 0, k = 0;
	while(i < n1 && j < n2) {
		if(left_arr[i] > right_arr[j]) {
			arr[k] = right_arr[j];
			k++;
			j++;
			count += n1 - i;
		}
		else if(left_arr[i] < right_arr[j]) {
			arr[k] = left_arr[i];
			k++;
			i++;
		}
	}

	while(i < n1)
		arr[k++] = left_arr[i++];
	while(j < n2)
		arr[k++] = right_arr[j++];

}

int merge_sort(int arr[], int low, int high) {
	if(low < high) {
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}

}

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	merge_sort(arr, 0, n-1);

	printf("%d\n",count);

	return 0;
}