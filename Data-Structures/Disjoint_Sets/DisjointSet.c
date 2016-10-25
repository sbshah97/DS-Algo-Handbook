#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int edg[500001][2],ou[100001];
long long int findroot(long long int nfs[],long long int a)
{
	long long int t;
	if(nfs[a]<0)
	{
		return a;
	}
	else
	{
		t=findroot(nfs,nfs[a]);
		nfs[a]=t;
		return t;
	}
}
void disunion(long long int nfs[],long long int r1,long long int r2)
{
	if(fabs(nfs[r1])>fabs(nfs[r2]))
	{
		nfs[r2]=nfs[r1]+nfs[r2];
		nfs[r1]=r2;		
	}
	else
	{
		nfs[r1]=nfs[r1]+nfs[r2];
		nfs[r2]=r1;
	}	
}
int main()
{
		long long int n,m,u,v,k,w,sum=0,nfs[100001],r1,r2,total=0;
		printf("Number of points(objects) and number of connections: ");
		scanf("%lld%lld",&n,&m);
		printf("Connection between points u and v\n");
	//printf("**%lld%lld**",edg[0][2],edg[1][2]);
	//Nifty Storage Truck	
		//All are roots so intialised to -1
		for(k=1;k<=n;k++)
			nfs[k]=-1;
		for(k=0;k<m;k++)
		{
			printf("u v: ");
			scanf("%lld%lld",&u,&v);
			edg[k][0]=u;
			edg[k][1]=v;
			r1=findroot(nfs,edg[k][0]);
			r2=findroot(nfs,edg[k][1]);
			if(r1==r2)
			{
				printf("%lld and %lld are already in same set\n",edg[k][0],edg[k][1]);
				continue;
			}
			else
			{
				printf("Joining to sets with roots %lld and %lld\n",r1,r2);
				disunion(nfs,r1,r2);
			}			
		}
		return 0;
}
