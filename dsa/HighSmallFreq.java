import java.util.*;

public class HighSmallFreq {

    public static void HighSmallFrequency(int[] a, int n) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        int minFreq = n, maxFreq = 0;
        int maxElement = -1, minElement = -1;

        for (int i = 0; i < n; i++) {
            hash.put(a[i], hash.getOrDefault(a[i], 0) + 1);
        }

        for (int key : hash.keySet()) {
            int freq = hash.get(key);
            if (minFreq > freq) {
                minFreq = freq;
                minElement = key;
            }

            if (maxFreq < freq) {
                maxFreq = freq;
                maxElement = key;
            }
        }

        System.out.println("Highest frequency of element " + maxElement + " is " + maxFreq);
        System.out.println("Smallest Frequency of element " + minElement + " is " + minFreq);

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.println("Enter the " + n + " array elements: ");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        HighSmallFrequency(a, n);

    }
}
