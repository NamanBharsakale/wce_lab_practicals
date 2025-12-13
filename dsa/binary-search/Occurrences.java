import java.util.*;


public class Occurrences {
    public static int findOccurrence(int[] a,int n,int x){
        int lb = firstOccurrence(a,n,x);
        if(a[lb] != x) return 0;
        int ub = lastOccurrence(a,n,x);
        return (ub - lb + 1);
    }

    public static int firstOccurrence(int[] a, int n, int x){
        int low = 0, high = n -1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] == x){
                ans = mid;
                high = mid - 1;
            }
            else if(a[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
       return ans;

    }
    public static int lastOccurrence(int[] a, int n, int x){
        int low = 0, high = n -1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] == x){
                ans = mid;
                low = mid + 1;
            }
            else if(a[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return ans;
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

        System.out.print("Enter the Target: ");
        int target = sc.nextInt();

        System.out.print(target+" Occurred: "+findOccurrence(a,n,target));
    }
}
