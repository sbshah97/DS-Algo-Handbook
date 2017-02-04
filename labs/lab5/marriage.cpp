#include <bits/stdc++.h>

int n;

int stable(int prefer[2*n][n]) {
	//Array to store the partners of women
	int wPartner[N]
}

int main() {
	scanf("%d",&n);

	int prefer[2*n][n];

	for(int i = 0; i < 2*n-1; i ++) {
		for(int j = 0; j < n; j ++) {
			scanf("%d",&prefer[i][j]);
		}
	}

	stable(prefer);

	return 0;
}