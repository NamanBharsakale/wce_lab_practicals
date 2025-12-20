
public class FibonacciNth {

    public static int FibN(int n) {
        if (n <= 1) {
            return n;
        }

        return FibN(n - 1) + FibN(n - 2);
    }

    public static void main(String args[]) {
        System.out.print("7th Fibonacci Number: " + FibN(7));
    }
}