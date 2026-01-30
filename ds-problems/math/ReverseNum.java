import java.util.*;


public class ReverseNum {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("ENter a number: ");
        int num = sc.nextInt();
        int reverseNumber = 0;
        while(num > 0){
            int lastDigit = num % 10;
            reverseNumber = (reverseNumber * 10) + lastDigit;
            num = num / 10;
        }

        System.out.println("Reverse Number: "+reverseNumber);
    }
}
