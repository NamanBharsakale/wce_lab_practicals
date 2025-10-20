import java.util.Scanner;

public class InsertionSort {
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
        //Insertion SOrt
        for(int k = 1; k < n; k++){
            int temp = a[k];
            int ptr = k -1;
            while(ptr >= 0 && temp < a[ptr])
            {
                a[ptr + 1] = a[ptr];
                ptr = ptr - 1;
            }
            a[ptr + 1] = temp;
        }
    
        for(int i =0; i< n; i++){
            System.out.print(" "+a[i]);
        }
    }
}
