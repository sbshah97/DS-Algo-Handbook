// Component is connected or not  using disjoint set union 
// type 1 denotes there is an edges between u and v 
// type 2 denotes is this u and v connected
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[100001];
ll size[100001];
ll root(ll i)
{
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}
void unn(ll u,ll v)
{
    ll root_a=root(u);
    ll root_b=root(v);
    a[root_a]=root_b;
}
bool fnd(ll u,ll v)
{
    if(root(u)==root(v))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
3 6
2 1 2
1 1 2
2 1 2
2 1 3
1 2 3
2 1 3
*/
int main()
{
    ll t,i,type,n,j,q,u,v;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        //cout<<visit[i]<<" ";
        a[i]=i;
        size[i]=1;
        //cout<<a[i]<<" ";
    }
    while(q--)
    {
        cin>>type>>u>>v;
        if(type==1)   // union 
        {
            //union
            unn(u,v);
        }
        else   // checking connected or not 
        {
            // find
            ll p=fnd(u,v);
            //cout<<p<<" ";
            if(p)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        /*for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
    }
}