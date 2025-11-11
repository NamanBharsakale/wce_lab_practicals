import java.util.*;

class Person{
    int age;
    String name;

    public Person(int a,String n){
        age=  a;
        name = n;
    }

    public void showPerson(){
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
    }
}

class Citizen extends Person{
    String nat;
    public Citizen(int age,String name,String nationality){
        super(age,name);
        nat = nationality;
    }

    public void showCitizen(){
        super.showPerson();
        System.out.println("Nationality: "+nat);
    }
}

class Student extends Citizen{
    int rid;
    public Student(int age,String name,String nat,int id){
        super(age,name,nat);
        rid =id;
    }

    public void showStudent(){
        super.showCitizen();
        System.out.println("Id: "+rid);
    }
}

public class MultiLevelEx{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);

        System.out.print("Enter the Student name: ");
        String name  = sc.nextLine();

        System.out.print("Enter the student age ");
        int age = sc.nextInt();
        sc.nextLine();
        System.out.println("Enetr the Student Nationality: ");
        String nat = sc.nextLine();

        System.out.println("Enter the Student Rno: ");
        int rno = sc.nextInt();

        Student s= new Student(age,name,nat,rno);
        s.showStudent();
        s.showPerson();

        sc.close();
    }
}