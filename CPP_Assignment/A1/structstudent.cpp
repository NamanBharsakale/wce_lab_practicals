#include <stdio.h>
#include <string.h>

#define SUBJECTS 5

struct Student {
    int ID;
    char Name[50];
    float Marks[SUBJECTS];
    float Total;
    float Percentage;
    char Grade;
};

void InputStudent(struct Student *s) {
    printf("Enter Student Name: ");
    scanf("%s", s->Name);

    printf("Enter Student ID: ");
    scanf("%d", &s->ID);

    printf("Enter Marks for %d Subjects:\n", SUBJECTS);
    s->Total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        printf("  Subject %d: ", i + 1);
        scanf("%f", &s->Marks[i]);
        s->Total += s->Marks[i];
    }

    s->Percentage = (s->Total / (SUBJECTS * 100)) * 100;

    if (s->Percentage > 90)
        s->Grade = 'A';
    else if (s->Percentage >= 80)
        s->Grade = 'B';
    else if (s->Percentage >= 70)
        s->Grade = 'C';
    else if (s->Percentage >= 60)
        s->Grade = 'D';
    else if (s->Percentage >= 50)
        s->Grade = 'E';
    else if (s->Percentage >= 40)
        s->Grade = 'F';
    else
        s->Grade = 'G';
}

void DisplayStudent(const struct Student *s) {
    printf("\nName        : %s", s->Name);
    printf("\nID          : %d", s->ID);
    printf("\nTotal Marks : %.2f / 500", s->Total);
    printf("\nPercentage  : %.2f%%", s->Percentage);

    if (s->Grade == 'G')
        printf("\nGrade       : %c (Failed — Better Luck Next Time!)\n", s->Grade);
    else
        printf("\nGrade       : %c (Congratulations!)\n", s->Grade);
}

int main() {
    int n;
    printf("Enter Number of Students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Enter Details for Student %d ---\n", i + 1);
        InputStudent(&students[i]);
    }

    printf("\n===== STUDENT REPORT =====\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        DisplayStudent(&students[i]);
    }

    return 0;
}
