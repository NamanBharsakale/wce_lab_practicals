
abstract class Animal{
    abstract void eat();

    public void sleep(){
        System.out.println("Animal is sleeping");
    }

}

class Dog extends Animal{
    public void eat(){
        System.out.println("Dog is eating");
    }

    public void sleep(){
        System.out.println("Dog is sleeping");
    }

}



public class AbstractEx {
    public static void main(String arg[]){
        Animal d = new Dog();
        d.eat();
        d.sleep();
    }
    
}
