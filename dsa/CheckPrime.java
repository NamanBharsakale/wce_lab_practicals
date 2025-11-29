import java.util.*;

public class CheckPrime{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int c =0;

        int num = sc.nextInt();
        for(int i = 1; i <= Math.sqrt(num); i++){
            if(num%i == 0){
                c++;
                if((num/i) != i){
                    c++;
                }
            }
        }

        System.out.println(c == 2?"It is prime number" : "It is not prime number");

    }
}