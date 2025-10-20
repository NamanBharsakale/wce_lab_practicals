class PrintData {

    // Print integer
    public void print(int a) {
        System.out.println("Integer: " + a);
    }

    // Print double
    public void print(double a) {
        System.out.println("Double: " + a);
    }

    // Print string
    public void print(String a) {
        System.out.println("String: " + a);
    }
}

public class Assignment1e {
    public static void main(String[] args) {
        PrintData pd = new PrintData();

        pd.print(42);               // integer
        pd.print(3.14159);          // double
        pd.print("Hello, Java!");   // string
    }
}
