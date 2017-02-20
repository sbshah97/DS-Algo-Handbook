#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10];
int num;

void dfs(int source) {
	visited[source] = true;
	num += 1;
	for(int i = 0; i < adj[source].size(); ++i)
		if(visited[adj[source][i]] == false) {
			dfs(adj[source][i]);
		}
}

void initialize(int n) {
	for(int i = 0; i < n; i ++) 
		visited[i] = false;
}

int main() {
	//Number of nodes and edges resp.
	int n, m;
	scanf("%d %d", &n, &m);

	int x, y;
	for(int i = 0 ; i < m; i ++) {
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	initialize(m);

	int source;
	scanf("%d",&source);

	num = 0;
	if(visited[source] == false)
		dfs(source);

	printf("%d\n",n - num);

	return 0;
}
