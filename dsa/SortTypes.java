import java.util.*;

public class SortTypes {
    //Selection SOrt
    public static void selectionSort(int[] a,int n){

        for(int i = 0; i < n; i++){
            int min = a[i];
            int loc = i;
            for(int j = i + 1; j < n; j++){
                if(min > a[j]){
                    min = a[j];
                    loc = j;
                }
            }
            a[loc] = a[i];
            a[i]= min;

        }
        System.out.print("Sorting using selection sort: ");
        for(int k = 0; k < n; k++){
            System.out.print(a[k]+" ");
        }
    }

    //insertion Sort 
    public static void insertionSort(int[] a,int n){
        for(int i = 0; i < n - 1; i++){
            int temp = a[i+1];
            int ptr = i;

            while(ptr >= 0 && temp < a[ptr]){
                a[ptr+1] = a[ptr];
                ptr = ptr - 1;
            }
            a[ptr + 1] = temp;
        }
        System.out.print("Sorting using insertion sort: ");
        for(int k = 0; k < n; k++){
            System.out.print(a[k]+" ");
        }

    }


    public static void bubbleSort(int[] a, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0;j < n - 1; j++){
                if(a[j] > a[j+1]){
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
        }

        System.out.print("Sorting using bubble sort: ");
        for(int k = 0; k < n; k++){
            System.out.print(a[k]+" ");
        }
    }


    public static void bubbleSortRecursive(int[] a,int n,int i){
        if(n == 1){
            return;
        }
        if(i < n - 1){
            if(a[i] > a[i+1])
            {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1]= t;
            }
            bubbleSortRecursive(a,n,i+1);
        }
        else{
            bubbleSortRecursive(a,n-1,0);

        }

    }

    public static void insertionSortRecursive(int[] a,int n){
        if(n <= 1) return;

        insertionSortRecursive(a,n-1);// so it will move when n = 2 such that n - 1 will return

        int last = a[n-1];// 2- 1 = 1
        int j = n-2;// 2-2 = 0

        while(j >= 0 && a[j] >= last){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = last;


    }

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
        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the " + n + " elements : ");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        mergeSort(a,0,n-1);
        System.out.print("Sorting using recursive insertion sort: ");
        for(int k = 0; k < n; k++){
            System.out.print(a[k]+" ");
        }
    }
}