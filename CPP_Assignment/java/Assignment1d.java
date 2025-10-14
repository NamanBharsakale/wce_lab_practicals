class Operations {

    // Sum of two integers
    public int operate(int a, int b) {
        return a + b;
    }

    // Product of two doubles
    public double operate(double a, double b) {
        return a * b;
    }

    // Concatenation of two strings
    public String operate(String a, String b) {
        return a + b;
    }
}

public class Assignment1d {
    public static void main(String[] args) {
        Operations op = new Operations();

        int sum = op.operate(10, 20);
        double product = op.operate(5.5, 2.0);
        String concatenated = op.operate("Hello, ", "World!");

        System.out.println("Sum of integers: " + sum);
        System.out.println("Product of doubles: " + product);
        System.out.println("Concatenated string: " + concatenated);
    }
}
