#include <stdio.h>
#include <stdlib.h>

void shell_sort(int arr[], int n) {
	int gap, i;
	
	for(gap = n/2; gap > 0; gap /= 2) {
		for(i = gap; i < n; i ++) {
			int temp = arr[i];
			int j;
			for(j = i; j <= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

int main() {

	int n,i;
	scanf("%d",&n);
	int arr[n];

	for(i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	shell_sort(arr, n);

	for(i = 0; i < n; i ++)
		printf("%d ",arr[i]);

	return 0;
}