import converter.*;
import java.util.*;

public class TestConv {
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        temp  t = new temp();
        System.out.println("Enter the Temperature in Celcius: ");
        double c = sc.nextDouble();
        System.out.println("converted in Fahrenheight: "+t.celcTofahr(c));
        System.out.println("Converted in kelvin: "+t.celcToKelv(c));

        System.out.println("Enter temperature in Fahrenheight: ");
        double f = sc.nextDouble();
        System.out.println("Converted in Celcius: "+t.fahrTocelc(f));
        System.out.println("Converted in Kelvin: "+t.fahrTokelv(f));

        System.out.println("ENter templarture in Kelvin: ");
        double k = sc.nextDouble();
        System.out.println("COnverted in celcius: "+t.KelvTocelc(k));
        System.out.println("Converted in Fahrenheght: "+t.KelvTofahr(k));



    }
}
