#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

typedef pair<int, int>ii;

vector<ii> G[MAX];
int dist[MAX], n, m;

int dijkstra(int f, int t) { // 0-indexed
    set<ii> s;
    set<ii>::iterator si;
    
    fill(dist, dist+n, inf);
    dist[f] = 0;
    s.insert(ii(0, f));
    while (s.size() != 0) {
        si = s.begin();
        int u = si->second;
        s.erase(si);
        for (int i= 0; i< G[u].size(); i++) {
            int v = G[u][i].second;
            int wt = G[u][i].first;
            if (dist[v] > dist[u]+wt) {
                if (dist[v] != inf)
                    s.erase(s.find(ii(dist[v],v)));
                dist[v] = dist[u] + wt;
                s.insert(ii(dist[v], v));
            }
        }
    }
    return dist[t];
}
