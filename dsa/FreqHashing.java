import java.util.*;

public class FreqHashing {
    public static void findFreq() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the array size: ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.print("Enter " + n + " elements : ");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int[] hash = new int[10];

        for (int i = 0; i < n; i++) {
            hash[a[i]]++;
        }

        while (true) {
            int l = sc.nextInt();
            if (l < 0)
                break;
            System.out.println(l + " repeated " + hash[l] + " times ");
        }
    }

    public static void findCharFreq() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str = sc.nextLine(); // Must be lowercase otherwise it will be ArrayOutOfBoundsException
        char[] ch = str.toCharArray();

        int[] hash = new int[26];
        try {
            for (int i = 0; i < str.length(); i++) {
                hash[(ch[i] - 'a')]++;
            }

            while (true) {
                System.out.print("Enter the char: ");
                char c = sc.next().charAt(0);
                if (c == 'Q')
                    break;
                System.out.println(c + " repeated : " + hash[c - 'a'] + " times");
            }
        } catch (Exception ex) {
            System.out.print("Eror: " + ex);
        }
    }

    public static void findHash() {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();// for input of word

        int[] hash = new int[256];
        char[] ch = str.toCharArray();
        for (int i = 0; i < str.length(); i++) {
            hash[(int) ch[i]]++;
        }

        while (true) {
            System.out.print("Enter the char: ");
            char c = sc.next().charAt(0);
            if (c == 'Q')
                break;
            System.out.println(c + " repeated : " + hash[(int) c] + " times");
        }
    }

    public static void main(String args[]) {
        findFreq();
        findCharFreq();
        findHash();

    }
}
