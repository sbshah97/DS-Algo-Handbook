#include <bits/stdc++.h>
using namespace std;

int vis[100],adj[100][100],n,d[100],s,d1,h[100],adj1[100][100];

void relax() {
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			if((adj[i][j]!=0 || i==n) && h[i]+adj[i][j]<h[j])
				h[j]=h[i]+adj[i][j];
		}
	}
}

void bellman()
{
	h[n]=0;
	for(int i=0;i<n;i++)
	{	relax();
		//for(int j=0;j<=n;j++)
		//	cout<<h[j]<<" ";
		//cout<<endl;
	}

	int f=1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(adj[i][j]!=0 && h[i]+adj[i][j]<h[j])
			{
				f=-1;
				break;
			}
		}
	}
	if(f==-1)
	{	cout<<"Neg weight cycle";
		exit(0);
	}
}

int min_dis()
{
	int i,min1=INT_MAX,min2=-1;
	for(i=0;i<n;i++)
	{
		if(d[i]<min1 && vis[i]==0)
		{	min1=d[i];
			min2=i;
		}
	}
	return min2;
}


void dij()
{	int i;
	for(i=0;i<n;i++)
	{
		int x=min_dis();

		if(x==-1)
			return;
		vis[x]=1;
		int j;
		for(j=0;j<n;j++)
		{
			if(adj[x][j]!=0 && d[j]>d[x]+adj1[x][j])
				d[j]=d[x]+adj1[x][j];

		}
	}
}

int main() {
	cout<<"Enter number of vertices and edges:";
	cin >> n >> e;
	cout<<"Enter adjacency matrix of graph:\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>adj[i][j];

	for(int i=0;i<n;i++)
		h[i]=INT_MAX;

	bellman();

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]!=0)
			{	
				adj1[i][j]=adj[i][j]+h[i]-h[j];
			}
		}

	cout<<"Shortest paths:\n";

	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{	d[j]=INT_MAX;
			vis[j]=0;
		}

		d[i]=0;
		dij();

		for(int j=0;j<n;j++)
		{	if(d[j]==INT_MAX)
				cout<<"Nil ";
			else
			cout<<d[j]-h[i]+h[j]<<" ";
		}
		cout<<endl;
		
	}
	//cout<<"Shortest path:"<<d[d1]-h[s]+h[d1];

}