import java.util.Scanner;

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
public class traversals {
    public static Node createTree(Node root){
        Scanner sc = new Scanner(System.in);
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
        System.out.println("Preorder:");
        preorderTraversal(root);
        System.out.println("Inorder: ");
        inorderTraversal(root);
        System.out.println("Postorder:");
        postorderTraversal(root);
    }
    private static void preorderTraversal(Node root) {
        if(root == null) return;
        System.out.print(root.data+" ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
        
    }
    private static void inorderTraversal(Node root) {
        if(root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data+" ");
        inorderTraversal(root.right);
    }
    private static void postorderTraversal(Node root) {
        if(root == null) return;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data+" ");

    }
    
}
