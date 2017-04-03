#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int cost[10][10];
int a[10][10];
int i, j, c;


int main() {

	//Enter number of vertices and edges
	int v, e;
	scanf("%d %d",&v,&e);

	//Enter edge cost in the matrix
	for(int k = 1; k <= e; k ++) {
		scanf("%d %d %d",&i,&j,&c);
		a[i][j] = c;
		cost[i][j] = c;
	}

	for(i = 1; i <= v; i ++) {
		for(j = 1; j <= v; j ++) {
			if(a[i][j] == 0 && i != j)
				a[i][j] = INF;
		}
	}

	for(int k = 1; k <= v; k ++) {
		for(i = 1; i <= v; i ++) {
			for(j = 1; j <= v; j ++) {
				a[i][j] = min(a[i][j], (int)a[i][k] + (int)a[k][j]);
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		for(int j = 1; j <= v; j ++) {
			if(a[i][j] != INF) {
				printf("%d ", a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}