class Team {
    private String[] members;
    private int count;
    private final int MAX_SIZE = 10;

    public Team() {
        members = new String[MAX_SIZE];
        count = 0;
    }

    public void addMember(String name) {
        if (count < MAX_SIZE) {
            members[count] = name;
            count++;
        } else {
            System.out.println("Team is full! Cannot add more members.");
        }
    }

    public void addMember() {
        if (count < MAX_SIZE) {
            members[count] = "Unknown" + (count + 1);
            count++;
        } else {
            System.out.println("Team is full! Cannot add more members.");
        }
    }

    public void displayTeam() {
        System.out.println("Team Members (" + count + "):");
        for (int i = 0; i < count; i++) {
            System.out.println((i + 1) + ". " + members[i]);
        }
        System.out.println("------------------------");
    }
}

public class Assignment1f {
    public static void main(String[] args) {
        Team myTeam = new Team();

        // Add members by name
        myTeam.addMember("Alice");
        myTeam.addMember("Bob");
        myTeam.addMember("Charlie");

        // Add generic members
        myTeam.addMember();
        myTeam.addMember();

        // Display team members
        myTeam.displayTeam();
    }
}
