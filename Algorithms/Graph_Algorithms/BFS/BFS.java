import java.util.LinkedList;
import java.util.Queue;

public class Graph {
    
    int[][] graph;
    
    public Graph(int[][] g) {
        graph = g;
    }
    
    public void bfs(int start) {
        int actual;
        boolean[] visited = new boolean[graph.length];
        Queue<Integer> q = new LinkedList<Integer>();
        System.out.println(start);
        visited[start] = true;
        q.offer(start);
        while(!q.isEmpty()) {
            actual = q.poll();
            for(int i = 0; i < graph.length; i++) {
                if(graph[actual][i] > 0 && !visited[i]) {
                    System.out.println(i);
                    visited[i] = true;
                    q.offer(i);
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Graph g = new Graph(new int[][]{
                                        {0,1,1,-1},
                                        {1,0,1,-1},
                                        {1,1,0,1},
                                        {-1,-1,1,0} });
        g.bfs(0);
    }
    
}
