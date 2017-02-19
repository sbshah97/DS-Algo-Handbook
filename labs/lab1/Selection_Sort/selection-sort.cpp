#include <bits/stdc++.h>

int arr[100];

void selection(int n) {
	for(int i = 0; i < n - 1; i++) {
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
}

void printArr(int n) {
	for(int i = 0; i < n; i ++) 
		printf("%d ",arr[i]);
	printf("\n");

}

int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	selection(n);

	printArr(n);

	return 0;
}