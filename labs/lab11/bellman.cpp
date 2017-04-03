#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V, E;
	list <pair<int, int> > *adj; 

public:
	Graph(int v, int e);
	void addEdge(int u, int v, int w);
	void printGraph();
	void BellmanFord(int src);
};

Graph::Graph(int v, int e) {
	this->V = v;
	this->E = e;
	adj = new list<pair <int, int> >[v];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
}

void Graph::printGraph() {
	for(int i = 0; i < (this->V); i ++) {
		printf("%d ->",i);
		for(const auto& p : adj[i]) {
			cout << p.first << " ";
		}
		printf("\n");
	}
}

void Graph::BellmanFord(int src) {
	int V = this->V;
	int E = this->E;
	vector<int> dist;

	//Step 1: Initialize all distances as infinite
	for(int i = 0; i < V; i ++) {
		dist.push_back(INT_MAX);
	}
	dist[src] = 0;

	//Step 2: A simple shortest path from src to 
	//any other vertex can have at most (|V|-1) edges
	for(int i = 1; i < V; i ++) {
		for(list<pair <int, int>>::iterator it = adj[i].begin(); it != adj[i].end; ++it) {
			int u = adj[i];
			int v = (*it).first;
			int w = (*it).second;
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	//Step 3: Check for negative weight cycles
	for(int i = 0; i < e; i ++) {
	} 
}

int main() {
	int n, e;
	scanf("%d %d",&n,&e);

	Graph g(n, e);

	int u, v, w;
	for(int i = 0; i < e; i ++) {
		scanf("%d %d %d",&u,&v,&w);
		g.addEdge(u, v, w);
	}

	g.printGraph();

	return 0;
}