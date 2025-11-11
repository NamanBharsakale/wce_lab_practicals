interface Addition{
    public void add(int a,int b);
}

interface Substraction{
    public void sub(int a,int b);
}

class Operation implements Addition,Substraction{
    public void add(int a,int b){
        System.out.println("Addition is "+(a+b));
    }

    public void sub(int a,int b){
        System.out.println("Substraction is "+(a-b));
    }
}

public class InterfaceEx{
    public static void main(String args[]){
        Operation op= new Operation();
        op.add(2,3);
        op.sub(3,2);
    }
}