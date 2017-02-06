#include <bits/stdc++.h>
#include <time.h>

int inv(int arr[], int n) {
	int count = 0;

	for(int i = 0; i < n-1; i ++) {
		for(int j = i+1; j < n; j ++) {
			if(arr[i] > arr[j])
				count++;
		}
	}
	return count;
}

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++) {
		scanf("%d",&arr[i]);
	}

	clock_t begin = clock();

	int count = inv(arr, n);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	//printf("%d\n",count);

	printf("The time spent for sorting is %f seconds.\n",time_spent);

	return 0;
}