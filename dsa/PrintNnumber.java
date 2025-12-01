import java.util.*;

public class PrintNnumber{
    public static void printNumber(int i,int n){
        if(i > n){
            return;
        }
        System.out.print(i+" ");
        printNumber(i+1,n);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num = sc.nextInt();

        printNumber(1,num);
    }
}