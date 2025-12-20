import java.util.Scanner;

public class Armstrong{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int number= num;
        int armNum = 0;

        while(num > 0){
            int lastDigit = num % 10;
            armNum = armNum + (lastDigit * lastDigit * lastDigit); // Math.pow(lastDigit,3);
            num = num / 10;
        }

        if(armNum == number){
            System.out.println("It is an armstrong number");
        }
        else{
            System.out.println("It is not an armstrong number");
        }

    }
}