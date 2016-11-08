#include <stdio.h>

//Variable declaration
void dfs(int);
int G[20][20], visited[10], n;

//Main function
int main() {
    
    //Variable declaration
    int i,j;
    printf("Enter number of vertices\n >");
    scanf("%d",&n);

    printf("Enter the adjacency matrix\n");
    //Read the adjacency matrix
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            scanf("%d",&G[i][j]);

    //Visited is initialised to zero
    for(i = 0; i < n; i ++)
        visited[i] = 0;

    dfs(0);

    return 0;
}

void dfs(int i) {
    
    //Variabvle declaration
    int j;
    printf("%d ",i);

    //Mark the visited region
    visited[i] = 1;

    //Visit the rest of the nodes in the graph
    for(j = 0; j < n; j ++)
        if(!visited[j] && G[i][j] == 1)
            dfs(j);
}