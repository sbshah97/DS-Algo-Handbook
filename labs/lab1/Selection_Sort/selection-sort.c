#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	int n, count = 0;
	scanf("%d",&n);

	int arr[n];

	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	for(int i = 0; i < n - 1; i ++) {
		int small = i;
		for(int j = i+1; j < n; j ++) {
			count += 1;
			if(arr[j] < arr[small])
				small = j;
		}

		int temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;
	}

	printf("The number of iterations spent for Selection Sort is %d swaps.\n",count);

	return 0;
}