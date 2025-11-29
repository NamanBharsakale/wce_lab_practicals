import java.util.*;
public class GreatestCommonDivisor{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter two numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        for(int i = Math.min(num1,num2); i >=1;i--){
            if((num1 % i == 0 ) && (num2 % i == 0)){
                System.out.print(""+i+" ");
                break;
            }
        }

    }
}