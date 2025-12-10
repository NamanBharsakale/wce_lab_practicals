import java.util.*;
;
public class LowerBound {
    public static int lowerBound(int[] a,int n,int target){
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + high/2;

            if(a[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            mid = (low+high)/2;
        }
        return ans;
    }
    public static int upperBound(int[] a,int n,int target){
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + high/2;

            if(a[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            mid = (low+high)/2;
        }
        return ans;
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

        System.out.print("Enter the Target: ");
        int Target = sc.nextInt();

        System.out.println("Lower Bound of "+Target+" is "+lowerBound(a,n,Target));
        System.out.println("Upper Bound of "+Target+" is "+upperBound(a,n,Target));
    }

    
}
