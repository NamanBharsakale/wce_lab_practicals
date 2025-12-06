import java.util.*;


public class LCM{

    public static int getGCD(int a,int b){
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
        System.out.print("Enter two numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int gcd = getGCD(num1,num2);


        int lcm = num1 * num2/gcd;
        System.out.print("LCM is "+lcm);

        
    }
}