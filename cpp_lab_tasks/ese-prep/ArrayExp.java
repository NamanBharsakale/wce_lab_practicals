import java.util.*;
class ArrayOperation {
    public static int MAX = 5;
    void insert(int arr[],int i,int val)throws ArrayIndexOutOfBoundsException,NullPointerException,IllegalArgumentException{
        if(val < 0){
            throw new IllegalArgumentException("Negative Values not allowed..");
        }

        if(i < 0  || i > ArrayOperation.MAX){
            throw new ArrayIndexOutOfBoundsException("Index Out of reach");
        }

        if(arr == null){
            throw new NullPointerException("Invalid Array ");
        }

        arr[i] = val;
        System.out.println("Inserted..");
    }

    void delete(int arr[],int i) throws ArrayIndexOutOfBoundsException,NullPointerException,IllegalArgumentException{
        if(i < 0  || i > ArrayOperation.MAX){
            throw new ArrayIndexOutOfBoundsException("Index Out of reach");
        }

        if(arr == null){
            throw new NullPointerException("Null array can't be accepted..");
        }

        if(arr[i] == -1){
            throw new IllegalArgumentException("Value is already deleted..");
        }

        arr[i] = -1;
        System.out.println("Deleted..");
    }

    void search(int arr[],int val)throws ArrayIndexOutOfBoundsException,NullPointerException,IllegalArgumentException{
        if(val < 0){
            throw new IllegalArgumentException("Negative Values not allowed..");
        }

        if(arr == null){
            throw new NullPointerException("Invalid Array ");
        }

        for(int i = 0; i < ArrayOperation.MAX;i++){
            if(arr[i] == val){
                System.out.println("Found it..");
                return;
            }
        }
        System.out.println("Not present in Array");
    }
}
public class ArrayExp{
    public static void main(String[] args) {
        int arr[] = new int[ArrayOperation.MAX];
        ArrayOperation a = new ArrayOperation();
        try{
            a.insert(arr, 0, 12);
            //a.insert(arr, -1, 11);

            a.search(arr,12);
            a.insert(arr, 2, 89);

            a.delete(arr, 8);

        }
        catch(NullPointerException e){
            System.out.println("Error: "+e);
        }
        catch(ArrayIndexOutOfBoundsException ai){
            System.out.println("Error: "+ai);
        }
        catch(IllegalArgumentException i){
            System.out.println("Error: "+i);
        }
    }
}