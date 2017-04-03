#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class Graph {

	int V;
	list <pair <int, int> > *adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
	void printGraph();
};

Graph::Graph(int v) {
	this -> V = v;
	adj = new list<pair <int, int> >[V];  
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int s) {
    set< pair<int, int> > setds;
 
    vector<int> dist(V, INF);
 
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    while (!setds.empty()) {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        int u = tmp.second;
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            int v = (*i).first;
            int weight = (*i).second;
 
            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void Graph::printGraph() {
	for(int i = 0; i < (this->V); i ++) {
		printf("%d ->",i);
		for(const auto& p : adj[i]) {
			cout << p.first << " " << p.second << " ";
		}
		printf("\n");
	}
}

int main() {
	//Vertices and edges in the graph
	int v, e;
	scanf("%d %d",&v,&e);
	
	//Call constructor
	Graph g(v);

	//Make the graph by adding all the edges
	int x, y, z;
	for(int i = 0; i < e; i ++) {
		scanf("%d %d %d",&x,&y,&z);
		g.addEdge(x, y, z);
	}

	g.shortestPath(0);

	g.printGraph();

	return 0;
}