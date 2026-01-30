import java.util.*;



public class TopoSort{
    public static void dfs(int num,int v,int[] visited,ArrayList<ArrayList<Integer>> adj,Stack<Integer> st){
        visited[num]=1;
        for(int node: adj.get(num)){
            if(visited[node]==0){
                dfs(node,v,visited,adj,st);
            }
        }
        st.push(num);
    }
    public static void main(String[] args){
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
        System.out.print("Adj List: ");
        for(int i =0 ; i<v;i++){
            System.out.println(i+" :-> "+adj.get(i));
        }
        int[] visited = new int[v];
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                dfs(i,v,visited,adj,st);
            }
        }
        while(!st.isEmpty()){
            System.out.print(" "+st.pop());
        }
    }
}