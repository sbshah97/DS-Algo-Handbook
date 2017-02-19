#include <bits/stdc++.h>

int arr[100];

int max(int a, int b, int c) {
	return (a > (b > c ? b : c) ? a : (b > c ? b : c));
}

int maxCrossingSum(int low, int mid, int high) {
	int sum = 0;
	int left_sum = INT_MIN;
	for(int i = mid; i >= low; i ++) {
		sum += arr[i]
		if(sum > left_sum) 
			left_sum = sum;
	}

	sum = 0;
	int right_sum = INT_MIN;
	for(int i = high; i > mid; i ++) {
		sum += arr[i];
		if(sum > right_sum)
			right_sum = sum;
	}

	return (right_sum + left_sum);
}

int maxSubArray(int low, int high) {
	if(low == high) {
		return arr[low];	
	}
	 int mid = (low + high) / 2;

	 return (max(maxSubArray(low, mid), maxSubArray(mid+1, high), maxCrossingSum(low, mid, high)));
}

int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	int max = maxSubArray(0, n-1);

	printf("%d\n", max);

	return 0;

}