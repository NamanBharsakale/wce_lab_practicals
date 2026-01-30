import java.util.*;

class Student{
    int sid;
    String sname;
    static int scount = 0;

    public Student(int id,String name){
        sid = id;
        sname = name;
        scount++;
    }

    public void show(){
        System.out.println("Id: "+sid);
        System.out.println("Name: "+sname);
    }

    public static void showCollege(){
        System.out.println("Welcome to WCE");
        System.out.println("Total STudent Count: "+scount);
    }

}

public class StaticEx{
    public static void main(String ars[]){
        Student s1 = new Student(10,"Naman");
        s1.show();

        Student.showCollege();

        Student s2 = new Student(16,"Suresh");
        s2.show();

        Student.showCollege();

    }
}