import java.util.*;


public class BubbleSort {
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.err.println("Enter the size of array: ");
        n = sc.nextInt();
        int[] a = new int[n];
        System.out.print("Enter "+n+" element: ");

        for(int i = 0; i<n; i++){
            a[i] = sc.nextInt();
        }
        //Bubble Sort

        for(int k = 1; k<n;k++){
            int pos = 0;
            while(pos < (n-k)){ 
                if(a[pos] > a[pos + 1]){
                    int t = a[pos];
                    a[pos] = a[pos + 1];
                    a[pos + 1] = t;
                }
                 pos = pos + 1;

            }
        }

        for(int i =0; i< n; i++){
            System.out.print(" "+a[i]);
        }
    }
}
