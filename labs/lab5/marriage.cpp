#include <bits/stdc++.h>
#define n 3

int m[1000], w[1000], mar[2000],[1000];

int stable(int prefer[2*n][n]) {
	//Array to store the partners of women
}

int main() {
	// int n;
	// scanf("%d",&n);

	int prefer[2*n][n];

	for(int i = 0; i < 2*n; i ++) {
		for(int j = 0; j < n; j ++) {
			scanf("%d",&prefer[i][j]);
		}
	}

	stable(prefer);

	return 0;
}