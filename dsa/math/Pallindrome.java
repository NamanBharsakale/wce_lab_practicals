import java.util.*;


public class Pallindrome {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("ENter a number: ");
        int num = sc.nextInt();
        int number = num;
        int reverseNumber = 0;
        while(num > 0){
            int lastDigit = num % 10;
            reverseNumber = (reverseNumber * 10) + lastDigit;
            num = num / 10;
        }

        if(reverseNumber == number){
            System.out.println(number+" is pallindrome number.");
        }
        else{
            System.out.println("It is not pallidrome number");
        }
    }
}
