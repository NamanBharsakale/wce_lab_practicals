import java.util.*;



public class RecursionProblems {

    public static int FactN(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        return (n * FactN(n-1));
    }

    public static void FibN(int a,int b,int n){
        if(n == 0){
            return;
        }
        System.out.print(a+" ");
        int t = a;
        a = b;
        b = t + b;

        FibN(a,b,n-1);
    }

    public static int[] RevN(int[] a,int i,int n){
        if(i >= n/2){
            return a;
        }
        int t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;

        return RevN(a,i+1,n);

    }

    public static boolean isPallindrome(char[] c,int i,int n){
        if(i >= n / 2) {
            return true;
        }

        
        if(c[i] != c[n - i - 1]){
            return false;
        }
        
        return isPallindrome(c,i+1,n);

    }



    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("ENter a number: ");
        int num = sc.nextInt();


        System.out.println("Factorial of number: "+FactN(num));
        System.out.println("Fibonacci Series upto "+num+ " terms is : ");
        FibN(0,1,num);
        System.out.println();



        int[] a = {10,20,30,40};
        System.out.println("Reverse of array: ");
        int[] r= RevN(a,0,a.length);
        for(int x : r){
            System.out.print(x+" ");
        }
        

        String str = "namn";
        System.out.println("Given String is Pallindrome: "+isPallindrome(str.toCharArray(),0,str.length()));
        

        sc.close();
    }
}
