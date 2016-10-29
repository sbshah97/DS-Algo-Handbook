public class Graph {
    
    final int INF = 99999;
    int[][] graph;
    boolean[] visited;
    
    public Graph(int[][] g) {
        graph = g;
    }
    
    public void prim(int start) {
        visited = new boolean[graph.length];
        int[] parent = new int[graph.length];
        int[] cost = new int[graph.length];
        int actual = start, last;
        
        parent[start] = INF;
        visited[start] = true;
        
        for(int i = 0; i < graph.length - 1; i++) {
            last = actual;
            actual = minCostNode(graph[last]);
            visited[actual] = true;
            parent[actual] = last;
            cost[actual] = graph[actual][last];
        }
        
        // Printing results:
        for(int i = 0; i < parent.length; i++) {
            System.out.println("Parent of " + i + " is " + parent[i]);
        }
        System.out.println("Total cost: " + sumArr(cost));
    }
    
    private int sumArr(int[] arr) {
        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    private int minCostNode(int[] row) {
        int min = 0;
        for(int i = 1; i < row.length; i++) {
            if(row[i] < row[min] && !visited[i]) {
                min = i;
            }
        }
        return min;
    }
    
    public static void main(String[] args) {
        final int INF = 99999;
        Graph g = new Graph(new int[][]{
                                        {INF,  4,  4,  6,INF},
                                        {4,  INF,  2,INF,INF},
                                        {4,    2,INF,  1,INF},
                                        {6,  INF,  1,INF,  9},
                                        {INF,INF,INF,  9,INF} });
        g.prim(4);
    }
    
}
