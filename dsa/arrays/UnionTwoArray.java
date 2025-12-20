import java.util.*;

import javax.sql.rowset.serial.SerialArray;

public class UnionTwoArray {

    public static int[] unionArray1(int[] a1,int [] a2,int n1,int n2){
        TreeSet<Integer> tset = new TreeSet<>();
        int i = 0;
        while(true){
            if(i < n1)
            {
                tset.add(a1[i]);
            }

            if(i < n2){
                tset.add(a2[i]);
            } 
            i++;
            if(i >= n1 && i >= n2){
                break;
            }

        }
        
        int[] union = tset.stream().mapToInt(Integer::intValue).toArray();
        return union;
    }
    //Optimal Solution
    public static int[] unionArray2(int[] a1,int [] a2,int n1,int n2){
        ArrayList<Integer> list = new ArrayList<>();

        int i = 0;
        int j =0;
        while(i < n1 && j < n2){
            if(a1[i] <= a2[j]){
                if( list.size() == 0 || list.get(list.size()-1) != a1[i]){
                    list.add(a1[i]);
                    
                }
                i++;
            }
            else{
                if(list.size() == 0 || list.get(list.size()-1) != a2[j]){
                    list.add(a2[j]);
                    
                }
                j++;
            }
        }
        while(i < n1){
            if( list.size() == 0 || list.get(list.size()-1) != a1[i]){
                    list.add(a1[i]);
                    
                }
                i++;
        }

        while(j < n2){
            if(list.size() == 0 || list.get(list.size()-1) != a2[j]){
                    list.add(a2[j]);
                    
                }
                j++;
        }
        int[] union = list.stream().mapToInt(Integer::intValue).toArray();
        return union;

    }

    public static int[] intersectionArray(int[] a1,int[] a2,int n1,int n2){
        ArrayList<Integer> list = new ArrayList<>();

        int i = 0; 
        int j = 0;
        while(i< n1 && j < n2){
            if(a1[i] < a2[j]){
                i++;
            }else if(a1[i] > a2[j]){
                j++;
            }else{
                list.add(a1[i]);
                i++;
                j++;
            }
        }

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
    
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the size of the 1st array: ");
        int n1 = s.nextInt();

        int[] a1 = new int[n1];
        System.out.print("Enter the size of the 2nd array: ");
        int n2 = s.nextInt();

        int[] a2 = new int[n2];

        System.out.print("Enter "+n1+" elemenst: ");
        for(int i =0 ; i < n1; i++){
            a1[i] = s.nextInt();
        }
        System.out.print("Enter "+n2+" elemenst: ");
        for(int i =0 ; i < n2; i++){
            a2[i] = s.nextInt();
        }

        System.out.print("Union Array : ");
        for(int x: unionArray2(a1, a2, n1, n2)){
            System.out.print(" "+x);// or we can return it by array by uding toArray() method
        }

        System.out.print("Intersection array: ");

        for(int x: intersectionArray(a1, a2, n1, n2)){
            System.out.print(" "+x);// or we can return it by array by uding toArray() method
        }





        
    }

}
