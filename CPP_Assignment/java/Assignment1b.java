class Customer {
    private int cid;
    private String cname;
    private int age;
    private String city;

    public Customer() {
        this.cid = 0;
        this.cname = "Unknown";
        this.age = 0;
        this.city = "Not specified";
    }

    public Customer(int cid, String cname, int age, String city) {
        this.cid = cid;
        this.cname = cname;
        this.age = age;
        this.city = city;
    }

    public void display() {
        System.out.println("----- Customer Details -----");
        System.out.println("Customer ID: " + cid);
        System.out.println("Name: " + cname);
        System.out.println("Age: " + age);
        System.out.println("City: " + city);
        System.out.println("----------------------------");
    }
}

public class Assignment1b {
    public static void main(String[] args) {
        Customer c1 = new Customer();
        Customer c2 = new Customer(101, "Amit", 25, "Mumbai");
        Customer c3 = new Customer(102, "Sneha", 28, "Pune");
        Customer c4 = new Customer(103, "Rahul", 30, "Delhi");
        Customer c5 = new Customer(104, "Priya", 22, "Nashik");
        Customer c6 = new Customer(105, "Karan", 27, "Nagpur");

        c1.display();
        c2.display();
        c3.display();
        c4.display();
        c5.display();
        c6.display();
    }
}
