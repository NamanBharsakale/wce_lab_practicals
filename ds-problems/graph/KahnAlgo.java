import java.util.*;


public class KahnAlgo{

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
        }

        int[] indegree = new int[v];

        for(int i=0;i<v;i++){
            for(int num: adj.get(i)){
                indegree[num]++;
            }
        }
        Queue<Integer> q= new LinkedList<>();
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.offer(i);
            }
        }
        
        ArrayList<Integer> l = new ArrayList<>();
        while(!q.isEmpty()){
            int n=q.poll();
            l.add(n);
            for(int node: adj.get(n)){
                indegree[node]--;
                if(indegree[node]==0){
                    q.offer(node);
                }
            }
        }
        System.out.print(l);
    }
}