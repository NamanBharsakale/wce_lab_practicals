class Film {
    private String name;
    private String language;
    private String type;
    private int duration;

    public Film() {
        this.language = "Hindi";
        this.duration = 3;
        this.name = "Unknown";
        this.type = "Drama";
    }

    public Film(String name, String language, String type, int duration) {
        this.name = name;
        this.language = language;
        this.type = type;
        this.duration = duration;
    }

    public void display() {
        System.out.println("----- Film Details -----");
        System.out.println("Name: " + name);
        System.out.println("Language: " + language);
        System.out.println("Type: " + type);
        System.out.println("Duration: " + duration + " hrs");
        System.out.println("------------------------");
    }

    public void destroy() {
        System.out.println("Destructor (simulated) called for film: " + name);
    }
}

public class Assignment1 {
    public static void main(String[] args) {
        Film film1 = new Film();
        film1.display();

        Film film2 = new Film("Inception", "English", "Sci-Fi", 2);
        film2.display();

        film1.destroy();
        film2.destroy();
    }
}
