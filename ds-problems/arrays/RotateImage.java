

public class RotateImage{
    private static int[][] RotateMatrix(int[][] matrix, int n, int m) {
        int[][] rotate = new int[n][m];

        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                rotate[j][(n-1)-i] = matrix[i][j];
            }
        }

        return rotate;
    }
    public static void main(String args[]){
        int[][] matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        for(int i = 0; i <matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }

        matrix = RotateMatrix(matrix, matrix.length,matrix[0].length);
        System.out.println("Rotated Matrix: ");
        for(int i = 0;i< matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }

    
}