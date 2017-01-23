#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d",&n);

	int arr[n], max2;

	for(int i = 0; i < n ; i ++)
		scanf("%d",&arr[i]);
	int max1 = -99999999;
	// int sum = 0;

	// for(int i = 0; i < n; i ++) {
	// 	for(int j = i; j < n; j ++) {
	// 		for(int k = i; k <= j; k++) {
	// 		 	sum += arr[k];
	// 		}
	// 		if(sum > max)
	// 			max = sum;
	// 		sum = 0;
	// 	}
	// }

	for(int i = 0; i < n; i ++) {
		max2 = 0;
		for(int j = i; j < n; j ++) {
			max2 += arr[j];
			if(max2 > max1)
				max1 = max2;
		}
	}

	printf("%d\n",max1);	
	
	return 0;
}