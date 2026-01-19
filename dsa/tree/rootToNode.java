import java.util.*;

class Node{
    int data;
    Node left;
    Node right;

    public Node(int key){
        data = key;
        left = null;
        right = null;
    }
}
public class rootToNode {
    static Scanner sc = new Scanner(System.in);

    public static Node createTree(Node root){
        int key=sc.nextInt();

        if(key == -1) return null;

        root = new Node(key);
        System.out.print("Enter left of "+key+": ");
        root.left = createTree(root.left);
        System.out.print("Enter right of "+key+": ");
        root.right = createTree(root.right);


        return root;
    }
    public static void main(String[] args) {
        System.out.print("Enter Tree Root: ");
        Node root = createTree(null);
        System.out.println("Enter Node:");
        int x = sc.nextInt();
        ArrayList<Integer> path = new ArrayList<>();
        System.out.print("Path Exist: "+hasPath(root,path,x));
        System.out.print("Path: "+path);

        
    }

    public static boolean hasPath(Node root, ArrayList<Integer> path,int x){
        if(root==null) return false;

        path.add(root.data);

        if(x == root.data) return true;

        if(hasPath(root.left,path,x) || hasPath(root.right,path,x)){
            return true;
        }

        path.remove(path.size()-1);
        return false;
    }
}