#include <bits/stdc++.h>

int fib(int n) {
	int arr[n];

	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i <= n; i ++) 
		arr[i] = arr[i-1] + arr[i-2];

	return arr[n];
}

int main() {
	int n;
	scanf("%d",&n);

	int fibo = fib(n);

	printf("%d\n",fibo);

	return 0;
}