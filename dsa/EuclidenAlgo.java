//Eucliden Algorithm
import java.util.*;


public class EuclidenAlgo{

    public static int gcd(int a,int b){
        while(a > 0 && b > 0){
            if(a > 0 && b > 0){
                if(a > b) a = a % b;
                else b = b % a;
            }

            
        }
        if(a == 0) return b;
        return a;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter two numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        System.out.println("GCD: "+gcd(num1,num2));

    }
}