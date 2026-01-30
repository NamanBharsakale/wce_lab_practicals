import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = s.nextInt();

        int[] a = new int[n];

        System.out.print("Enter "+n+" elemenst: ");
        for(int i =0 ; i < n; i++){
            a[i] = s.nextInt();
        }

        System.out.print("ENter element to search: ");
        int data = s.nextInt();
        for(int i = 0; i < n; i++){
            if(a[i] == data){
                System.out.print("Found at "+i);
                break;
            }
        }
    }
    
}
