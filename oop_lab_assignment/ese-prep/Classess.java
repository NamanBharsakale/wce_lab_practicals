import java.util.*;

class Operation{
    int a,b;
    
    public Operation(int n1,int n2){
        a = n1;
        b = n2;
    }

    public void sum(){
        System.out.println("Sum is "+(a+b));
    }

    public void sub(){
        System.out.println("Substraction is "+(a-b));
    }

    
}

public class Classess{
    public static void main(String args[]){
        Operation op = new Operation(4,5);
        op.sum();
        op.sub();




    }
}