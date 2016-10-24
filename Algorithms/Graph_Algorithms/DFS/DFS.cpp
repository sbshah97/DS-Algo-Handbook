#include <bits/stdc++.h>

#define MAX ...

vector<int> G[MAX];

/* this array may be initialized with false
    eg.: memset(visited, false, sizeof visited) */
bool visited[MAX];

void dfs(int at) {
    if(visited[at])
        return;
    visited[at] = true;
    for (int i= 0; i< (int)G[at].size(); i++)
        dfs(G[at][i]);
}
