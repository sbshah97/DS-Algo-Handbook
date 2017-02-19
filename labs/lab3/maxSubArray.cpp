#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++) 
		scanf("%d",&arr[i]);

	int sum = 0;
	int max = arr[0];

	for(int i = 0; i < n; i ++) {
		if(sum >= 0)
			max += sum;
		else
			max = sum;
		if(max > sum)
			max = sum;
	}

	printf("%d\n",max);

	return 0;
}