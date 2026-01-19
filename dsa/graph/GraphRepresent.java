import java.util.*;

public class GraphRepresent{
    static Scanner sc = new Scanner(System.in);

    public static void matrixRepresentaion(){
        System.out.print("Enter the number of vertices: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = sc.nextInt();
        int[][] mat = new int[n+1][n+1]; // For 1 based indexing
        System.out.println("Mark The Edges by Entering (u,v):-");
        for(int i = 1; i <= e; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            mat[u][v] = 1;
            mat[v][u] = 1;  //For Undirected
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void listRepresentaion(){
        System.out.print("List Representation: ");
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        System.out.print("Enter the number of vertices: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int e = sc.nextInt();
        for(int i =0 ; i <= n;i++){
            list.add(new ArrayList<>());
        }

        System.out.println("Mark The Edges by Entering (u,v):-");
        for(int i = 1; i <= e; i++){

            int u = sc.nextInt();
            int v = sc.nextInt();
            list.get(u).add(v);
            list.get(v).add(u);
        }
        
        for(ArrayList<Integer> l: list){
            if(list.indexOf(l) == 0) continue;
            System.out.println(list.indexOf(l)+" :-> "+l);
        }
    }
    public static void main(String args[]){
        listRepresentaion();

    }
}