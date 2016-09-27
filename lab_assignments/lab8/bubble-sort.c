#include <stdio.h>
#include <stdlib.h>

void bubble(int a[], int n) {
	int i,j,temp;
	for(i = 0 ; i < n ; i ++) {
		for(j = 0 ; j < n - 1 ; j ++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}

	}
}

int main() {
	//Input number of variables into 
	// the shell.
	int n,i;
	scanf("%d",&n);
	int a[n];

	//Input elements into the array
	for(i = 0 ; i < n ; i ++) {
		scanf("%d",&a[i]);
	}

	bubble(a, n);

	for(i = 0; i < n; i ++) {
		printf("%d ",a[i]);
	}
}