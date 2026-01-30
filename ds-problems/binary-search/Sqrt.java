import java.util.Scanner;

public class Sqrt {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

         
        System.out.print("ENter number: ");
        int k = sc.nextInt();

        int low = 0, high = k;
        int ans=-1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if((mid*mid) <= k){
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
