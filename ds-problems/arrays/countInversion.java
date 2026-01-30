import java.util.ArrayList;
import java.util.Scanner;
public class countInversion {
    static int cnt;
    public static void mergeSort(int[] a,int low,int high){
        if(low >= high) return;
            int mid = (low+high)/2;
            mergeSort(a,low,mid);
            mergeSort(a,mid+1,high);

            merge(a,low,mid,high);
        
    }

    public static void merge(int[] a,int low,int mid,int high){
        int left = low;
        int right = mid + 1;
        ArrayList<Integer> arr= new ArrayList<>();
        while(left <= mid && right <= high){
            if(a[left] <= a[right]){
                arr.add(a[left]);
                left++;
            }
            else{
                arr.add(a[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while(left <= mid){
            arr.add(a[left]);
            left++;
        }

        while(right <= high){
            arr.add(a[right]);
            right++;
        }

        for(int i = 0;i < arr.size(); i++){
            a[low + i] = arr.get(i);
        }
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array size: ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.print("Enter " + n + " elements : ");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        mergeSort(a, 0, n-1);
        System.out.println("COunt pf Inversion: "+cnt);
        
    }
}
