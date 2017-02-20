#include <bits/stdc++.h>

using namespace std;

vector<int> vert[10];
bool visited[10];

void dfs(int s) {
	visited[s] = true;
	printf("%d->",s);
	for(int i = 0; i < vert[s].size(); ++i) {
		if(visited[vert[s][i]] == false) {
			dfs(vert[s][i]);
		}
	}
}

void initialize(int v) {
	for(int i = 0; i < v; i ++) {
		visited[i] = false;
	}
}

int main() {
	int v, e;
	scanf("%d",&v);
	scanf("%d",&e);

	int x, y;
	for(int i = 0; i < e; i ++) {
		scanf("%d %d",&x,&y);
		vert[x].push_back(y);
		vert[y].push_back(x);
	}

	initialize(v);

	printf("Begin->");

	for(int i = 0; i < v; i ++) {
		if(visited[i] == false) {
			dfs(i);
			printf("\n");
			//connectedComponents++;
		}
	}

	printf("End");
	//printf("Number of connected components\n->%d");
	return 0;
}