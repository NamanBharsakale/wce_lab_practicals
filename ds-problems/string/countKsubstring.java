package dsa.string;
import java.util.*;

public class countKsubstring {
    public static int atLeastKBrute(String s, int k) {
    int n = s.length();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        Set<Character> set = new HashSet<>();
        for (int j = i; j < n; j++) {
            set.add(s.charAt(j));
            if (set.size() >= k)
                count++;
        }
    }
    return count;
}

    public static void main(String[] args) {
        String str = "abbcdda";

        int n = str.length();

        if(n < 0) System.err.println("Not Valid");

        Map<Character,Integer> map = new HashMap<>();
        int left = 0, count = 0;

        for(int right =0;right < n; right++){
            char ch = str.charAt(right);
            map.put(str.charAt(right),map.getOrDefault(str.charAt(right), 0)+1);
            if(map.size()>3)                //here 3 is k
            {
                char lch = str.charAt(left);
                map.put(lch,map.get(lch)-1);
                if(map.get(lch)==0){
                    map.remove(lch);
                }
                left++;
            }
            count+= right - left + 1;
        }
        System.err.println(count);
    }
}
