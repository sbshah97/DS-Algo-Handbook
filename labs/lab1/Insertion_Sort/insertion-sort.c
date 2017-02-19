//Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//Variable declaration
	int n; 
	long long int count = 0;
	scanf("%d",&n);

	int arr[n+1], j, x;

	for(int i = 0; i < n; i ++) 
		scanf("%d",&arr[i]);
	
	//Programming Logic
	for(int i = 0; i < n; i ++) {
		x = arr[i];
		j = i - 1;
		while(arr[j] > x && j >= 0) {
			count += 1;
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = x;
	}

	printf("The number of iterations for Insertion Sort is %lld .\n", count);

	return 0;
}