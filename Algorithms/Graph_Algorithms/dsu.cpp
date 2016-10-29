#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define pb push_back

class UnionFind {
        private : vector<int> parent, rank, size;
                  int numberOfDisjointSets;

        public :
                  UnionFind(int N) {
                          rank.assign(N+1, 0);
                          parent.assign(N+1, 0);                                //creates N placeholders in parent vector
                          size.assign(N+1, 1);
                          for( int i = 1; i <= N; i++ ) {                      // 0 to N-1 vertices
                                  parent[i] = i;
                          }
                          numberOfDisjointSets = N;
                  }

                  int findSet(int i) {
                          if(parent[i] == i)
                                  return i;
                          else
                                  parent[i] = findSet( parent[i] );
                          return parent[i];
                  }

                  bool isSameSet(int i, int j) {
                          if( findSet(i) == findSet(j))
                                  return true;
                          else
                                  return false;
                  }

                  void unionSet(int i, int j) {
                          if(!isSameSet(i,j)){
                                  int x = findSet(i);
                                  int y = findSet(j);
                                  if(rank[x] > rank[y]) {
                                          parent[y] = x;
                                          size[x] += size[y];
                                          size[y] = 0;
                                  }
                                  else{
                                          parent[x] = y;
                                          size[y] += size[x];
                                          size[x] = 0;
                                          if(rank[x] == rank[y])
                                                  rank[y]++;
                                  }
                          numberOfDisjointSets--;
                          }
                  }

                  int numDisjointSets(void) {
                          return numberOfDisjointSets;
                  }

                  int sizeOfSet(int i) {
                          return size[findSet(i)];
                  }
};

int main(){
        UnionFind u(7);
        u.unionSet(1, 2);
        u.unionSet(3, 4);
        u.unionSet(5, 6);
        u.unionSet(1, 5);
        u.unionSet(3, 7);
        u.unionSet(1, 3);

        cout << u.sizeOfSet(3) << endl;
        cout << u.sizeOfSet(1) << endl;
        
        return 0;
}
