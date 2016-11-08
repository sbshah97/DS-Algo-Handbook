#include <stdio.h>
#include <stdlib.h>

//Function to swap variables 
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Function to obtain partition for the unsorted array 
int partition(int arr[], int first, int last) {
	int pivot = arr[last];
	int i = first - 1;
	int j;

	for(j = first; j <= last - 1; j ++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[last]);
	return (i + 1);
}

//Function to use the QuickSort Algorithm
void quickSort(int arr[], int first, int last) {
	if (first < last) {
		int part = partition(arr, first, last);

		//Separately sort elements before
		//and after partition
		quickSort(arr, first, part - 1);
		quickSort(arr, part + 1, last);
	}
}

//Printing the elements of the array.
void printArray(int arr[], int n) {
	int i;
	for(i = 0; i < n; i ++) 
		printf("%d\n",arr[i]);
}

//Main function execution of the array
int main() {

	//Declare variables in the program
	int n;
	scanf("%d",&n);
	int arr[n],i;

	//Inputting variables into the array
	for(i = 0; i < n; i ++) 
		scanf("%d",&arr[i]);

	//Call the quickSort function
	quickSort(arr, 0, n - 1);

	//Printing the sorted array
	printArray(arr, n);

	return 0;
}