import java.util.*;
public class DijkestraExample{

    public int[] dijkstra(int v, ArrayList<int[]>, int src){
        int[] dist = new int[v];
        PriorityQueue<int[]> q = new PriorityQueue<>((a,b)-> a[0]-b[0]);
        Arrays.fill(Integer.MAX_VALUE);

        q.offer(new int[]{0,src});
        while(!q.isEmpty()){
            int[] edge = q.poll();
            int dis = edge[0];
            int node = edge[1];
            for(int[] n: adj.get(node)){
                int weight = n[1];
                int no = n1[0];
                if(dist[no] > dis+weight){
                    dist[no] = dis+weight;
                    q.offer(new int[]{dist[no],no});
                }
            }
        }
        return dist;
    }
    public static void main(String[] args) {
        // Number of vertices and edges
        int V = 3, E = 3, S = 2;

        // Create adjacency list to represent the graph
        ArrayList<int[]>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }

        // Add edges to the graph
        adj[0].add(new int[]{1, 1});
        adj[0].add(new int[]{2, 6});
        adj[1].add(new int[]{2, 3});
        adj[1].add(new int[]{0, 1});
        adj[2].add(new int[]{1, 3});
        adj[2].add(new int[]{0, 6});

        Solution obj = new Solution();
        // Call dijkstra function and store the result
        int[] res = obj.dijkstra(V, adj, S);

        // Output the shortest distance from source to all nodes
        for (int i = 0; i < V; i++) {
            System.out.print(res[i] + " ");
        }
        System.out.println();
    }
}