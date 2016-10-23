#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node *next;
    int vertex;
} node;
 
node *G[20];
int visited[20];

void DFS(int i) {
  node *p;
  printf("n%d",i);
  p=G[i];
  visited[i] = 1;
  while(p != NULL) {
    i=p->vertex;
    if(!visited[i])
    DFS(i);
    p=p->next;
  }
}
