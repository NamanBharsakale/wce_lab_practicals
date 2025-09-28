import java.util.*;


public class OptimisedBubble {
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        n = sc.nextInt();
        int[] a = new int[n];
        System.out.print("Enter "+n+" element: ");

        for(int i = 0; i<n; i++){
            a[i] = sc.nextInt();
        }
        //Bubble Sort

        for(int i = n -1; i >= 1; i--){
            int didSwap = 0;
            for(int j = 0; j <= i -1; j++){
                if(a[j] > a[j +1]){
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                    didSwap = 1;
                }
            }
            if(didSwap == 0){
                break;
            }
        }
        for(int i =0; i< n; i++){
            System.out.print(" "+a[i]);
        }
    }
}
