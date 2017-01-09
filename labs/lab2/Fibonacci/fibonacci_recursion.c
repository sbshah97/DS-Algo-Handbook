#include <stdio.h>
#include <stdlib.h>

int fibo(int n) {
	if( n <= 1)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}

int main() {
	int n;
	scanf("%d",&n);

	int fib = fibo(n);

	printf("%d\n",fib);
}

