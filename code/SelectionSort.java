import java.util.*;

public class SelectionSort {
    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Size of array: ");
        n = sc.nextInt();

        int[] a = new int[n];
        
        System.out.print("Enter the "+n+"element : ");
        for(int i = 0; i< n; i++){
            a[i] = sc.nextInt();
        }

        // Selection Sort
        for(int i = 0; i < n - 1; i++){
            int min = a[i];
            int pos = i;
            for(int j = i; j < n; j++){
                if(min > a[j]){
                    min = a[j];
                    pos = j;
                }
            }

            a[pos] = a[i];
            a[i] = min;

        }

        for(int i = 0; i< n;i++){
            System.out.print(" "+a[i]);
        }

        sc.close();

    }


}