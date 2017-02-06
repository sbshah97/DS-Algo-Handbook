#include <bits/stdc++.h>

int merge(int arr[], int first, int mid, int last) {
	int len, i,j,k,*c, count = 0;
	len = last - first + 1;

	c = (int *)malloc(sizeof(int)*len);
	i = 0;
	j = first;
	k = mid;

	while(j <= mid-1 && k <= last) {
		if(arr[j] <= arr[k]) {
			c[i++] = arr[j++];
		}
		else {
			c[i++] = arr[k++];
			count += mid - j;
		}
	}

	while(j <= mid-1) {
		c[i++]=arr[j++];
	}

	while(k <= last) {
		c[i++] = arr[k++];
	}
	i = 0;

	// while(first <= last) {
	// 	arr[last++] = c[i++];
	// }

	for(int x = first; x <= last; x ++) {
		arr[x] = c[x];
	}

	return count;
}

int mergesort(int arr[], int first, int last) {
	int mid = (first + last) / 2;
	int count = 0;

	if(first < last) {
		count += mergesort(arr, first, mid);
		count += mergesort(arr, mid+1, last);
		count += merge(arr, 0, mid+1, last);
	}

	return count; 
}

int inv(int arr[], int n) {

	return mergesort(arr, 0, n);
}

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	int count = inv(arr, n-1);

	printf("%d\n",count);

	return 0;
}