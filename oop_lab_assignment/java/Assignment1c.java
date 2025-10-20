class Vector {
    private double[] arr;
    private int size;

    public Vector() {
        this.size = 5;
        this.arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0.0;
        }
    }

    public Vector(int size) {
        this.size = size;
        this.arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0.0;
        }
    }

    public void display() {
        System.out.print("Vector elements: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Destructor simulation
    public void destroy() {
        arr = null; // Allow garbage collector to free memory
        System.out.println("Vector memory released.");
    }
}

public class Assignment1c {
    public static void main(String[] args) {
        Vector v1 = new Vector(); 
        v1.display();

        Vector v2 = new Vector(8); 
        v2.display();

        v1.destroy();
        v2.destroy();
    }
}
