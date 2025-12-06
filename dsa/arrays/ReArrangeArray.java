import java.util.ArrayList;
import java.util.Scanner;

public class ReArrangeArray{
    public static void reArrange(int[] a,int n){
        ArrayList<Integer> pos = new ArrayList<>();
        ArrayList<Integer> neg = new ArrayList<>();

        for(int i = 0;i < n ;i++){
            if(a[i] > 0){
                pos.add(a[i]);
            }
            else{
                neg.add(a[i]);
            }
        }

        if(pos.size() > neg.size()){
            for(int i =0 ; i<neg.size();i++){
                a[2*i] = pos.get(i);
                a[2*i+1] = neg.get(i);
            }
        }
        else{
            for(int i =0 ; i<pos.size();i++){
                a[2*i] = pos.get(i);
                a[2*i+1] = neg.get(i);
            }
        }
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = s.nextInt();

        int[] a = new int[n];

        System.out.print("Enter "+n+" elemenst: ");
        for(int i =0 ; i < n; i++){
            a[i] = s.nextInt();
        }
        reArrange(a,n);
        for(int i = 0; i < n; i++){
            System.out.print(a[i]+" ");
        }
    }
}