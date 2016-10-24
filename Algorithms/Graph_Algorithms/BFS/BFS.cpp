#include <bits/stdc++.h>

using namespace std;

vector<int> G[MAX];

/* this visited array should be initialized with false
    eg.: memset(visited, false, sizeof visited) */
bool visited[MAX];

void BFS(int first) {
    queue<int>Q;
    Q.push(first);
    while (!Q.empty()) {
        int act = Q.front();
        visited[act] = true;
        Q.pop();
        for (int i= 0; i< G[act].size(); i++)
            if (!visited[G[act][i]])
                Q.push(G[act][i]);
    }
}
