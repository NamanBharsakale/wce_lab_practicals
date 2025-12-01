

public class PatternNum3{
    public static void main(String args[]){
        int c = 0;
        for(int i = 1; i <= 4; i++){
            

            for(int j = 1; j <= i; j++){
                System.out.print(j);
            }

            for(int k = 6; k >c; k--){
                System.out.print(" ");
            }

            for(int p = i; p >= 1; p--){
                System.out.print(p);
            }
            c = c + 2;
            System.out.println();
        }
    }
}