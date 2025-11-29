
import java.util.*;

public class CountDigit {
    public static void main(String[] args) {
        System.out.println("Enter the Number: ");
        Scanner sc= new Scanner(System.in);
        int num = sc.nextInt();
        int c = 0;

        while(num > 0){
            num = num / 10;
            c++;
        }

        System.out.println("Total digits is "+c);

        sc.close();
    }
}
