import java.util.*;



public class mergeSort {
    public static void merge_Sort(int[] arr, int low,int high){
        if(low >= high) return;
        int mid = (low+high)/2;
        
        merge_Sort(arr, low, mid);
        merge_Sort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
    
    public static void merge(int[] arr, int low, int mid, int high){
        Vector<Integer> v = new Vector<>();

        int left = low;
        int right = mid + 1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                v.add(arr[left]);
                left++;
            }
            else{
                v.add(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            v.add(arr[left]);
            left++;
        }

        while(right <= high){
            v.add(arr[right]);
            right++;
        }
        for(int i = low; i<= high;i++){
            arr[i] = v.get(i-low);
        }


    }


    public static void main(String[] args) {
        int n;
        System.out.println("Enetr the Size of the array: ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int[] a = new int[n];
        for(int i = 0;i<n; i++){
            a[i] = sc.nextInt();
        }

        merge_Sort(a,0,n-1);
        for(int i =0 ; i<n;i++){
            System.out.print(" "+a[i]);
        }

    }
    
}
