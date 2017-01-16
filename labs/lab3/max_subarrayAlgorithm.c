#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];

	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);

	int sum = 0;
	int max = arr[0];

	for(int i = 0; i < n; i ++) {
		if(sum >= 0)
			sum += arr[i];
		else
			sum = arr[i];
		if(sum > max)
			max = sum;
	}

	printf("%d\n",max);

	return 0;
}