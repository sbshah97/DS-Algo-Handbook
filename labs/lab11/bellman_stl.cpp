#include <bits/stdc++.h>
using namespace std;

void printList(vector<list <pair <int, int> > > adjList) {

}

void PrintNegCycle(vector< pair<int, int> > shortestDistances, int vertex, int startVertex) {
    if (vertex == startVertex) {
        printf("%d ", vertex);
    } else if (shortestDistances[vertex].second == 0) {
        PrintNegCycle(shortestDistances, startVertex, startVertex);
        printf("%d ", vertex);
    } else {
        PrintNegCycle(shortestDistances, shortestDistances[vertex].second, startVertex);
        printf("%d ", vertex);
    }
}
 
int bellmanFord(vector< list< pair<int, int> > > adjacencyList, int vertices, int startVertex, vector< pair<int, int> > & shortestDistances) {
    list< pair<int, int> >::iterator traverse;
    int i, j, k;
     

    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].first = INT_MAX;
        shortestDistances[i].second = -1;
    }
     
    // Setting distance to source = 0
    shortestDistances[startVertex].first = 0;
    shortestDistances[startVertex].second = 0;
     
    // The Algorithm that computes Shortest Distances
    for (i = 1; i <= vertices - 1; ++i) {
        for (j = 1; j <= vertices; ++j) {
            traverse = adjacencyList[j].begin();
             
            while (traverse != adjacencyList[j].end()) {
                if (shortestDistances[j].first == INT_MAX) {
                    //traverse = traverse->next;
                    ++traverse;
                    continue;
                }
                 
                // Checking for Relaxation
                if ((*traverse).second + shortestDistances[j].first < 
                                        shortestDistances[(*traverse).first].first) {
                    // Relaxation
                    shortestDistances[(*traverse).first].first = (*traverse).second
                                        + shortestDistances[j].first;
                    shortestDistances[(*traverse).first].second = j;
                }
                 
                ++traverse;
            }
        }
    }
     
    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) {
        traverse = adjacencyList[j].begin();
         
        while (traverse != adjacencyList[j].end()) {
            // Checking for further relaxation
            if ((*traverse).second + shortestDistances[j].first < 
                                        shortestDistances[(*traverse).first].first) {
                // Negative Cycle found as further relaxation is possible
                return j;
            }
             
            ++traverse;
        }
    }
     
    return -1;
}

int main() {
	int v, e, v1, v2, w;

	scanf("%d %d",&v,&e);

	vector< list <pair <int, int> > > adjList(v+1);


	for(int i = 1; i <= e; i ++) {
		scanf("%d %d %d",&v1,&v2,&w);
		adjList[v1].push_back(make_pair(v2, w));
	}

	printList(adjList);

	vector< pair <int, int> > shortestDist(v+1);

	int src;
	scanf("%d",&src);

	int value = bellmanFord(adjList, v, src, shortestDist);

	if(value == -1)
		printf("No negative cycles");
	else {
		printf("Negative Cycles present\n");

		PrintNegCycle(shortestDist, shortestDist[value].second, value);
		return 0;
	}

	for (int i = 1; i <= v; ++i) {
        printf("%d %d %d\n", i, shortestDist[i].first, shortestDist[i].second);
    }

	return 0;
}