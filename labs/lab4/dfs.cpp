#include<stdio.h>
#include<stdlib.h>

int v[100],n,n1;

struct node{
    int data;
    struct node * next;
}*rear[100],*start[100];

int edge[200],k,parent[100],back[200],k1;

void dfs(int u)
{
    v[u]=1;

    struct node* t;
    t = start[u];
    
    while(t != NULL) 
    {   
        if(v[t->data]==0)
        {   
            parent[t->data]=u;
            dfs(t->data);
            edge[k++]=u+1;
            edge[k++]=t->data+1;
        }
        else
        {   
            if(find(u,t->data))
            {
                back[k1++]=u+1;
                back[k1++]=t->data+1;
            }
            
        }
        t = t->next;
    }
    printf("Node:%d\n",(u+1));
}

int find(int j,int b)
{   int i;
    
    while(j!=-1)
    {
        j=parent[j];
        if(j==b)
            return 1;
    }
    return 0;
}

void main()
{
    int i,j,a,b;
    printf("Enter number of vertices:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        rear[i]=NULL;
        start[i]=NULL;
        
    }
    parent[0]=-1;
    printf("Enter number of edges:");
    scanf("%d",&n1);

    printf("Enter edges:");
    for(i=0;i<n1;i++)
    {
        scanf("%d%d",&a,&b);
        //parent[b-1]=a-1;
        struct node* p=(struct node*)malloc(sizeof(struct node));
        p->data=b-1;
        p->next=NULL;
        if(rear[a-1]!=NULL)
        {   
            rear[a-1]->next=p;
            rear[a-1]=p;
        }
        else
        {   start[a-1]=p;
            rear[a-1]=p;
        }
    }
    

    printf("DFS traversal:\n");
    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        dfs(i);
    }
    
    printf("Edges:\n");
    for(i=0;i<k;i+=2)
        printf("%d-%d\n",edge[i],edge[i+1]);

    printf("Back edges:\n");
    for(i=0;i<k1;i+=2)
        printf("%d-%d\n",back[i],back[i+1]);


}