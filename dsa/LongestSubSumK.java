import java.util.*;


public class LongestSubSumK {
    public static int subArraySumK(int[] a,int n,int k){
        int  i =0,sum =0, j = 0,c =0 , maxC =0;
        while(i < n && j < n){
            sum += a[j];
            if(sum == k){
                c = j - i + 1;
                if(maxC < c){
                    maxC = c;
                }
                i++;
                j = i;
                sum = 0;
            }
            else{
                j++;
            }
        }
        return maxC;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.print("ENter "+n+" elements: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }    
        System.out.print("ENter k: ");
        int k = sc.nextInt();
        System.out.print("Size: "+subArraySumK(a,n,k));
    }
}
