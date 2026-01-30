import java.util.*;


public class LongestSubSumK {
    public static int subArraySumK(int[] a,int n,int k){
        HashMap<Long,Integer> map = new HashMap<>();
        int maxC = 0;
        long sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];

            if(sum == k){
                maxC = Math.max(maxC, i +1);
            }
            long rem = sum - k;
            if(map.containsKey(rem)){
                int len = i - map.get(rem);
                maxC = Math.max(maxC, len);
            }

            if(!map.containsKey(sum)){
                map.put(sum, i);
            }
        }
        return maxC;

    }

    //Optimal Two pointer SLiding window
        public static int subArraySumK2(int[] a,int n,int k){
            int maxLen = 0,i = 0, j =0 ;
            long sum = a[0];

            while(j < n){

                if(i <= j && sum > k){
                    sum = sum - a[i];
                    i++;
                }
                if(sum==k){
                    maxLen = Math.max(maxLen,j-i+1);
                }
                j++;
                if(j < n) sum += a[j];
            }
            return maxLen;
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
