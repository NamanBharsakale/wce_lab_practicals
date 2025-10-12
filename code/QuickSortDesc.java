import java.util.*;

public class QuickSortDesc{

    public static void sortQuick(int[] arr, int low,int high){
        if(low < high){
            int pIndex = sortPartition(arr,low,high);
            sortQuick(arr,low,pIndex - 1);
            sortQuick(arr,pIndex+1,high);
        }
    }

    public static int sortPartition(int[] arr,int low,int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i < j){
            while(arr[i] <= pivot && i <= high - 1){
                i++;
            }
            while(arr[j] > pivot && j >= low+1){
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
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        for(int i = 0; i<5;i++){
            arr[i] = sc.nextInt();
        }

        sortQuick(arr,0,arr.length- 1);
        for(int i = 0; i<5;i++){
            System.out.print(arr[i]+" ");
        }
    }
}