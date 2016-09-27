#include <stdio.h>
#include <stdlib.h>

void selection(int arr[], int n) {
	int i,j, min_idx;

	for(i = 0; i < n - 1; i ++) {
		min_idx = i;
		for( j = i+1; j < n ; j ++) 
			if(arr[j] < arr[min_idx])
				min_idx = j;
		
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int main() {
	
	//Variable declaration
	int n,i;
	scanf("%d",&n);
	int arr[n];

	//
	for(i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	selection(arr, n);

	for(i = 0; i < n; i ++)
		printf("%d ",arr[i]);

}