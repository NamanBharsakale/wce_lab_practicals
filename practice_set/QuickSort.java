import java.util.*;

public class QuickSort{

    public static void qs(int[] arr, int low, int high){
        if(low < high){
            int partition_index = sortPivot(arr,low,high);
            qs(arr,low,partition_index - 1);
            qs(arr,partition_index+1,high);

        }
    }

    public static int sortPivot(int[] arr,int low, int high){
        int pivot = arr[low];
        int i = low;
        int  j = high;

        while(i < j){
            while(arr[i] <= pivot&& i <= high - 1){
                i++;
            }
            while(arr[j] >pivot && j >= low+1){
                j--;
            }
            if(i < j){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        int t = arr[low];
        arr[low] = arr[j];
        arr[j] = t;
        return j;
    }
   

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[5];
        System.out.println("Enter the elements in the array: ");
        for(int i=0;i<5;i++){
            arr[i] = sc.nextInt();
        }

        qs(arr,0,arr.length - 1);
        for(int i =0;i<5;i++){
            System.out.print(arr[i] + " ");
        }


    }
    }
