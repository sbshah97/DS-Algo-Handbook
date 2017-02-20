#include <bits/stdc++.h>

int inv(int arr[], int n) {
	int count = 0;
	for(int i = 0; i < n - 1; i ++) {
		for(int j = i + 1; j < n; j ++) {
			if(arr[i] > arr[j])
				count ++;
		}
	}

	return count;
}

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	int count = inv(arr, n);

	printf("%d\n",count);

	return 0;
}