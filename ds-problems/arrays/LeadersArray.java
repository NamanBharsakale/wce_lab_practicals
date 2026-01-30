import java.util.*;
public class LeadersArray {

    public static void printLeaders(int[] nums,int n){
        ArrayList<Integer> list = new ArrayList<>();

        int max = nums[n-1];
        list.add(max);

        for(int i = n-2; i>= 0; i--){
            if(max <= nums[i]){
                max = nums[i];
                list.add(nums[i]);
            }
        }
        Collections.reverse(list);
        for(int x: list){
            System.out.print(x+" ");
        }
    }
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = s.nextInt();

        int[] a = new int[n];

        System.out.print("Enter "+n+" elemenst: ");
        for(int i =0 ; i < n; i++){
            a[i] = s.nextInt();
        }

        printLeaders(a,n);
    }
}
