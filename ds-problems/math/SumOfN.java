import java.util.*;


public class SumOfN {


    public static int SumN(int n){
        if(n == 0){
            return 0;
        }
        return(n+(SumN(n-1)));
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = sc.nextInt();

        System.out.print("Sum of first "+num+" numbers is : "+SumN(num));
    }
}
