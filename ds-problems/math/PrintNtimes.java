import java.util.*;

public class PrintNtimes{

    public static void functionName(int n){
        if(n == 0){
            return;
        }
        System.out.println("functionName");
        functionName(n-1);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = sc.nextInt();

        functionName(num);
    }
}