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

    public static int countSubarray1(int[] a,int n,int k){
        int i = 0;
        int j = 0;
        int c = 0;
        int sum = 0;
        while(j < n){
            sum = sum ^ a[j];
            if(sum == k){
                c++;
            }

            j++;
            if(j == n){
                i = i + 1;
                j = i;
                sum = 0;
            }
        }
        return c;
    }

    public static int countSubarray2(int[] a,int n,int k){
        int c = 0,sum = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        for(int i = 0; i < n; i++){
            sum = sum ^ a[i];

            int rem = sum ^ k;
            c += map.getOrDefault(rem, 0);
            map.put(sum,map.getOrDefault(sum,0)+1);
            
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

        System.out.print("Total Subarrays: "+countSubarray1(a,n,k));
    }
}
