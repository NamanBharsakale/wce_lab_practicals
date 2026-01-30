import java.util.*;

public class FloorAndCeil {

    public static int ceilVal(int[] a,int n,int x) {
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high) / 2;
            if(a[mid] >=x){
                ans = a[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
     public static int floorVal(int[] a,int n,int x) {
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high) / 2;
            if(a[mid] <=x){
                ans = a[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
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
        int target = sc.nextInt();

        System.out.println("FLoor : "+floorVal(a,n,target));
        System.out.print("Ceil : "+ceilVal(a,n,target));
        
    }

}
