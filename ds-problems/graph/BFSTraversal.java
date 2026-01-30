import java.util.*;
public class BFSTraversal{
    public static void bfsTraversal(ArrayList<ArrayList<Integer>> adj, int i,int[] visited){
        System.out.print(i+" ");
        visited[i] = 1;
        
        for(int j = 0; j < adj.get(i).size();j++){
            int u = adj.get(i).get(j);
            if(visited[u] != 1){
                bfsTraversal(adj,u,visited);
            }
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the total vertices: ");
        int v = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = sc.nextInt();
        System.out.print("Mark "+e+" The Edges (u,v): ");
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i =0; i<v;i++){
            adj.add(new ArrayList());
        }
        for(int i = 0; i < e; i++){
            int u = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(w);
            adj.get(w).add(u); // For Undirected graph
        }
        System.out.print("Adj List: ");
        for(int i =0 ; i<v;i++){
            System.out.println(i+" :-> "+adj.get(i));
        }

        System.out.print("Traversal: ");
        int[] visited = new int[v];
        bfsTraversal(adj,0,visited);
    }
}