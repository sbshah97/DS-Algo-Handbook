#include <stdio.h>
#include <stdlib.h>

int fib[100000];

int fibo(int n) {
	if( n <= 1)
		return 1;
	if(fib[n] != 0)
		return fib[n];
	else {
		fib[n] = fibo(n-1) + fibo(n-2);
		return fib[n];
	}
}

int main() {
	int n;
	scanf("%d",&n);

	int fib = fibo(n);

	printf("%d\n",fib);
}

