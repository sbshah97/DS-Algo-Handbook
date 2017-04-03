#include <bits/stdc++.h>
using namespace std;

//Directed Graphs in C++
int main() {

	//Enter value of nodes and edges
	int n, e;
	scanf("%d %d",&n,&e);

	int e1,e2;
	vector<int> v[n+2];

	for(int i = 0; i < e; i ++) {
		scanf("%d %d",&e1,&e2);
		v[e1].push_back(e2);
	}

	for(int i = 1; i <= n; i ++) {
		cout <<"The edges which are linked to " << i << " are:\n";
		for(vector<int>::iterator it=v[i].begin(); it != v[i].end(); ++it) {
			cout << *it << " ";
		}
		printf("\n"); 
	}

	return 0;
}