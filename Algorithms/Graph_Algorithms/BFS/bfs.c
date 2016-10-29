#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/* maxVertices represents maximum number of vertices that can be present in the graph. */
#define maxVertices   100
/*Queue has five properties. capacity stands for the maximum number of elements Queue can hold.
  Size stands for the current size of the Queue and elements is the array of elements. front is the
 index of first element (the index at which we remove the element) and rear is the index of last element
 (the index at which we insert the element) */
typedef struct Queue
{
        int capacity;
        int size;
        int front;
        int rear;
        int *elements;
}Queue;
/* crateQueue function takes argument the maximum number of elements the Queue can hold, creates
   a Queue according to it and returns a pointer to the Queue. */
Queue * CreateQueue(int maxElements)
{
        /* Create a Queue */
        Queue *Q;
        Q = (Queue *)malloc(sizeof(Queue));
        /* Initialise its properties */
        Q->elements = (int *)malloc(sizeof(int)*maxElements);
        Q->size = 0;
        Q->capacity = maxElements;
        Q->front = 0;
        Q->rear = -1;
        /* Return the pointer */
        return Q;
}
void Dequeue(Queue *Q)
{
        /* If Queue size is zero then it is empty. So we cannot pop */
        if(Q->size==0)
        {
                printf("Queue is Empty\n");
                return;
        }
        /* Removing an element is equivalent to incrementing index of front by one */
        else
        {
                Q->size--;
                Q->front++;
                /* As we fill elements in circular fashion */
                if(Q->front==Q->capacity)
                {
                        Q->front=0;
                }
        }
        return;
}
int Front(Queue *Q)
{
        if(Q->size==0)
        {
                printf("Queue is Empty\n");
                exit(0);
        }
        /* Return the element which is at the front*/
        return Q->elements[Q->front];
}
void Enqueue(Queue *Q,int element)
{
        /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
        if(Q->size == Q->capacity)
        {
                printf("Queue is Full\n");
        }
        else
        {
                Q->size++;
                Q->rear = Q->rear + 1;
                /* As we fill the queue in circular fashion */
                if(Q->rear == Q->capacity)
                {
                        Q->rear = 0;
                }
                /* Insert the element in its rear side */ 
                Q->elements[Q->rear] = element;
        }
        return;
}



void Bfs(int graph[][maxVertices], int *size, int presentVertex,int *visited)
{
        visited[presentVertex] = 1;
        /* Iterate through all the vertices connected to the presentVertex and perform bfs on those
           vertices if they are not visited before */
        Queue *Q = CreateQueue(maxVertices);
        Enqueue(Q,presentVertex);
        while(Q->size)
        {
                presentVertex = Front(Q);
                printf("Now visiting vertex %d\n",presentVertex);
                Dequeue(Q);
                int iter;
                for(iter=0;iter<size[presentVertex];iter++)
                {
                        if(!visited[graph[presentVertex][iter]])
                        {
                                visited[graph[presentVertex][iter]] = 1;
                                Enqueue(Q,graph[presentVertex][iter]);
                        }
                }
        }
        return;
        

}
/* Input Format: Graph is directed and unweighted. First two integers must be number of vertces and edges 
   which must be followed by pairs of vertices which has an edge between them. */
int main()
{
        int graph[maxVertices][maxVertices],size[maxVertices]={0},visited[maxVertices]={0};
        int vertices,edges,iter;
        /* vertices represent number of vertices and edges represent number of edges in the graph. */
        scanf("%d%d",&vertices,&edges);
        int vertex1,vertex2;
        for(iter=0;iter<edges;iter++)
        {
                scanf("%d%d",&vertex1,&vertex2);
                assert(vertex1>=0 && vertex1<vertices);
                assert(vertex2>=0 && vertex2<vertices);
                graph[vertex1][size[vertex1]++] = vertex2;
        }
        int presentVertex;
        for(presentVertex=0;presentVertex<vertices;presentVertex++)
        {
                if(!visited[presentVertex])
                {
                        Bfs(graph,size,presentVertex,visited);
                }
        }
        return 0;



}
