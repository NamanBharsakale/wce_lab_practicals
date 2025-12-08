import java.util.*;
public class LongestSubXorK {
    
    public static int countSubarray(int[] a,int n, int k){
        
        int c = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n;j++){
                sum = sum ^ a[j];

                if(sum == k){
                    c++;
                }
            }
        }
        return c;
    }
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.print("ENter "+n+" elements: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }    
        System.out.print("ENter k: ");
        int k = sc.nextInt();

        System.out.print("Total Subarrays: "+countSubarray(a,n,k));
    }
}
