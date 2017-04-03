#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[], int e1, int e2) {
	g[e1].push_back(e2);
	g[e2].push_back(e1);

	//return g;
}

void printGraph(std::vector<int> g[], int n) {
	for(int i = 0; i < n; i ++) {
		cout <<"The edges which are linked to " << i << " are:\n";
		for(vector<int>::iterator it=g[i].begin(); it != g[i].end(); ++it) {
			cout << *it << " ";
		}
		printf("\n"); 
	}
}

int main() {

	//No of vertices and edges 
	int v, e;
	scanf("%d %d",&v,&e);
	vector<int> g[v];

	int e1, e2;
	//'e' lines follow
	for(int i = 0; i < e; i ++) {
		scanf("%d %d",&e1,&e2);
		addEdge(g, e1, e2);
	}

	printGraph(g, v);

	return 0;
}