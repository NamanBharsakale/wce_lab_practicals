package converter;

public class temp {
    
    // Celsius to Fahrenheit
    public double celcTofahr(double c) {
        // Use 9.0/5.0 to force decimal math
        return (c * 9.0 / 5.0) + 32;
    }

    // Fahrenheit to Celsius
    public double fahrTocelc(double f) {
        // Use 5.0/9.0 to force decimal math
        return (f - 32) * (5.0 / 9.0);
    }

    // Celsius to Kelvin
    public double celcToKelv(double c) {
        return c + 273.15;
    }

    // Kelvin to Celsius
    public double KelvTocelc(double k) {
        return k - 273.15;
    }

    // Fahrenheit to Kelvin
    public double fahrTokelv(double f) {
        // Use 5.0/9.0 and 273.15
        return ((f - 32) * (5.0 / 9.0)) + 273.15;
    }

    // Kelvin to Fahrenheit
    public double KelvTofahr(double k) {
        // Use 273.15 and 9.0/5.0
        return (k - 273.15) * (9.0 / 5.0) + 32;
    }
}