import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            
            int b = new int[n-1];
            int sum = 0;
            for(int j = 0; j < n-1; j++){
                b[j] = a[j] - a[j+1];
                sum += b[j];
            }


        }
    }
}