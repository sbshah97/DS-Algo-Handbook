#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i = 0; i < n; i ++) 
		scanf("%d",&arr[i]);

	int max_so_far = arr[0];
	int curr_max = arr[0];
 
   	for (int i = 1; i < n; i++) {
		curr_max = std::max(arr[i], curr_max+arr[i]);
        max_so_far = std::max(max_so_far, curr_max);
   	}

	printf("%d\n",max_so_far);

	return 0;
}