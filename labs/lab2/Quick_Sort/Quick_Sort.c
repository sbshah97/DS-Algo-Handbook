#include <stdio.h>
#include <stdlib.h>

int A[1000000];

int partition(int low, int high) {
    int pivot = A[high];  
 	int temp;
    int i = (low - 1);  

    for (int j = low; j <= high- 1; j++) {
        if (A[j] <= pivot) {
            i++;    
            //swap arr[i] and arr[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    //swap arr[i + 1] and arr[high])
    temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;

    return (i + 1);
}


void quickSort(int low, int high) {
	int pivot;
	if(low <= high) {
		pivot = partition(low, high);
		quickSort(low, pivot-1);
		quickSort(pivot+1, high); 
	}
}


int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) 
		scanf("%d",&A[i]);

	quickSort(0, n-1);

	for(int i = 0; i < n ; i ++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}