#include <stdio.h>
#include <stdlib.h>
long long int *c[100005],*d[100005];
long long indeg[300005]={0},outdeg[300005]={0},vis[300005]={0},a[300005]={0},b[300005]={0},stack[600005]={0};
long long p=0;
long long arr[300005]={0};
long long DFS(long long i)
{
	long long j;
	vis[i]=1;
	for(j=0;j<arr[i];j++)
	{
		if(vis[c[i][j]]==0)
		{
			DFS(c[i][j]);
		}
	}
	stack[p++]=i;
	return 0;
}

int main()
{
	
	p=0;
	long long n,e,v,final=0,i,j,co,costMin;
	for(i=0;i<300005;i++)
	{
		indeg[i]=0;
		outdeg[i]=0;
		vis[i]=0;
	}
	printf("Enter 2 integers: <#vertices> <#edges>\n");
	scanf("%lld%lld",&v,&e);
	printf("Enter %lld pairs of 2 integers: <a> <b> where there is a directed edge from a->b\n",e);
	for(i=1;i<=e;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		outdeg[a[i]]++;
		indeg[b[i]]++;
	}
	for(i=1;i<=v;i++)
	{
		c[i]=(long long int *)malloc((outdeg[i]+1)*sizeof(long long int));
	}
	for(i=0;i<300005;i++)
		arr[i]=0;
	for(i=1;i<=e;i++)
	{
		c[a[i]][arr[a[i]]++]=b[i];
	}
	for(i=1;i<=v;i++)
	{
		if(vis[i]==0)
			DFS(i);
	}
	i = p-1;
	printf("Topological sorting for given graph is:\n");
	for (i = p-1; i>=0; i--)
	{
		printf("%lld ",stack[i]);
		/* code */
	}
	printf("\n");
//		
	
	return 0;
}
