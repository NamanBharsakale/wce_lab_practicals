public class PatternStar3{
    public static void main(String args[]){


        for(int i = 1; i <= 5 ; i++){
            for(int j = 5; j >= i; j--){
                System.out.print(" ");
            }

            for(int p = 1; p <= i; p++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i = 5; i >= 1; i--){
        
            for(int p = 1; p <= (5 - i); p++){
                System.out.print(" ");
            }

            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }

            
            System.out.println();
        }
    }
}