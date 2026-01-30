import MyPackage.*;

public class PackageEx{
    public static void main(String args[]){
        Calci c= new Calci();
        System.out.println("Addition: "+(c.add(34,45)));
        System.out.println("Substraction: "+(c.sub(90,22)));
        System.out.println("Multiplicatiojn: "+(c.mult(3,20)));
        System.out.println("Division : "+(c.div(4,2)));

    }
}

