import java.util.*;

public class HashMapExample {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("ENter the string: ");
        String str = sc.next();

        HashMap<Character, Integer> hash = new HashMap<>();
        char[] ch = str.toCharArray();

        for (int i = 0; i < ch.length; i++) {
            hash.put(ch[i], hash.getOrDefault(ch[i], 0) + 1);
        }

        while (true) {
            System.out.print("Enter the char : ");
            char c = sc.next().charAt(0);
            if (c == 'Q')
                break;
            System.out.println(c + " repeated : " + hash.get(c) + " times");
        }

    }
}
