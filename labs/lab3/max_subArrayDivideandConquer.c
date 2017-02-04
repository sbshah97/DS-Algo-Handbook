#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[1000];

int maximum(int a, int b) {
	return (a > b) ? a : b;
}

int max(int a, int b, int c) {
	return maximum(maximum(a,b), c);
}

int maxCrossingSum(int low, int mid, int high) {
	//Calculate left sum of the array
	int sum = 0;
	int left_sum = INT_MIN;
	for(int i = mid; i >=low; i --) {
		sum += arr[i];
		if(sum > left_sum)
			left_sum = sum;
	}

	//Calculate right sum of the number
	sum = 0;
	int right_sum = INT_MIN;
	for(int i = mid+1; i <= high; i++) {
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

	int mid = (low+high) / 2;

	return (max(maxSubArray(low,mid), maxSubArray(mid+1,high), maxCrossingSum(low,mid,high)));
}


int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) 
		scanf("%d",&arr[i]);

	int max = maxSubArray(0, n -1);

	printf("%d",max);

	return 0;
}