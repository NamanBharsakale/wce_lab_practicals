//Less Time Complexivity
import java.util.*;

public class PrintAllDiv{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num = sc.nextInt();

        List<Integer> numbers = new ArrayList<>();

        for(int i = 1; i < Math.sqrt(num); i++){

            if(num % i == 0)
            {
                numbers.add(i);
                if((num/i) != i){
                    numbers.add(num/i);
                }
                
            }
        }

        Collections.sort(numbers);
        System.out.println("Divisors: "+numbers);
    }
}