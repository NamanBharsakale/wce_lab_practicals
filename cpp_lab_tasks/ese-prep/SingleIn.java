class Person{
    int age;
    String name;

    public Person(int a,String n){
        age = a;
        name = n;
    }

    public void showPerson(){
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
    }
}

class Student extends Person{
    int rid;
    public Student(int age,String name,int id){
        super(age, name);
        rid = id;
    }

    public void showStudent(){
        super.showPerson();
        System.out.println("Id: "+rid);
    }
}

public class SingleIn{
    public static void main(String[] args) {
        Student s = new Student(10, "Naman", 20);
        s.showStudent();
    }
}