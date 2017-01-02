#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int x;
	clock_t begin = clock();

	for(int i = 0; i < 10000; i ++) {
		x = 11;
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("The time spent for sorting is %f seconds.",time_spent);

	return 0;
}