import java.io.FileNotFoundException;
import java.io.FileReader;

public class ExcpetionEx{
    public static void main(String args[]){
        try{
            FileReader file = new FileReader("data.txt");
            System.out.println("File Found..");
        }
        catch(FileNotFoundException f){
            System.out.println("Error : file Not found"+f.getMessage());
        }
    }
}