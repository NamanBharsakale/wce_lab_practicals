import java.util.*;

public class ArrayProblems {

    public static void MaxElements(int[] a, int n){
        
        //Brute Force Solution: like using sorting then accessing last i.e, n -1 element
        //Optimal Soultion:
        int max = a[0];
        int maxLast = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++){
            if(max < a[i]){
                maxLast = max;
                max = a[i];
            }
            else if(max > a[i] && maxLast < a[i]){
                maxLast = a[i];
            }
        }

        System.out.println("Largest element: "+max);
        System.out.println("Second largest : "+maxLast);
    }

    public static void MinElements(int[] a, int n){
        
        //Brute Force Solution: like using sorting then accessing last i.e,0,1 element
        //Optimal Soultion:
        int min = a[0];
        int minLast = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            if(min > a[i]){
                minLast = min;
                min = a[i];
            }
            else if(min > a[i] && minLast < a[i]){
                minLast = a[i];
            }
        }

        System.out.println("Smallest element: "+min);
        System.out.println("Second smallets : "+minLast);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.print("ENter "+n+" elements: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        MaxElements(a,n);
        MinElements(a,n);

    }
}
