#include<cstdio>
#include<vector>
using namespace std;

struct edge{
    int src,dest,weight;
};

vector<edge> edgeList;
int n;
void BellmanFord(int src,int ans[]){
    for(int i=0;i<n;i++){
        ans[i]=-1u/2; //INT_MAX
    }
    ans[src]=0;
    for(int i=0;i<n-1;i++) //Relax n-1 times
    {
        for(auto edge:edgeList)// for all edges
        {
            if(ans[edge.src]!=-1u/2 && ans[edge.src]+edge.weight<ans[edge.dest]){
                ans[edge.dest]=ans[edge.src]+edge.weight;
            }
        }
    }
}
void addEdge(int u,int v,int w){
    edgeList.push_back(edge({u,v,w}));
    edgeList.push_back(edge({v,u,w}));
}
int main(){
    n=5;
    addEdge(1,2,3);
    addEdge(0,2,1);
    addEdge(3,4,3);
    addEdge(4,2,2);
    addEdge(1,3,6);
    int ans[n];// containing shortest distance to i
    BellmanFord(0,ans);
    for(int i=0;i<n;i++){
        printf("%d : %d\n",i,ans[i]);
    }
}
