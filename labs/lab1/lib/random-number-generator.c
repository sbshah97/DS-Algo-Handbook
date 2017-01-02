#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int n, i;
	scanf("%d",&n);

	int arr[n+1], j, x, count = 0;

	for(i = 0; i < n; i ++) {
		//scanf("%d",&arr[i]);
		arr[i] = rand() % 10023;
	}

	printf("%d\n",n);

	for(i = 0; i < n; i ++)
		printf("%d\n",arr[i]);
	
	return 0;
}