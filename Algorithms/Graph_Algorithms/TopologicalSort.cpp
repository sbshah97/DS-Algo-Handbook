#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > &adj, stack<int> &ordering,vector<int> &visited, int i)
{
	visited[i]=1;
	int x;
	for(x=0;x<adj[i].size();x++)
	{
		if(visited[adj[i][x]]==0)
			dfs(adj,ordering,visited,adj[i][x]);
	}
	ordering.push(i);
}

int main()
{
	int n,m; //no of vertices and edges
	cin>>n>>m;
	int i,j;
	vector<vector<int> > adj(n+1);
	int x,y;
	//Assume node vertices are between 1 to n
	while(m--)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	stack<int> ordering;
	vector<int> visited(n+1,0);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			dfs(adj,ordering,visited,i);
	}
	//print the ordering
	cout<<"The ordering is:\n";
	while(!ordering.empty())
	{
		cout<<ordering.top()<<" ";
		ordering.pop();
	}
	cout<<endl;
	return 0;
}