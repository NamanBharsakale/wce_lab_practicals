import java.util.Scanner;

public class NthRoot {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

         
        System.out.print("ENter number: ");
        int k = sc.nextInt();
        System.out.print("Enter the nth : ");
        int n = sc.nextInt();

        int low = 0, high = k;
        int ans=-1;
        while(low <= high){
            int mid = (low+high)/2;
            long val = (long)Math.pow(mid,n);
            if(val <= k){
                ans= mid;
                low= mid + 1;
            }
            else{
                high = mid - 1;
            }


        }

        System.out.println("Sqrt: "+ans);

    }
}
