#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    int m1, m2, m3;
    int total;
    float percentage;
};

int main()
{
    struct Student s[50];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Accept student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the roll number, name and marks of 3 subjects for student %d:\n", i + 1);
        scanf("%d %s %d %d %d", &s[i].roll, s[i].name, &s[i].m1, &s[i].m2, &s[i].m3);

        s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].percentage = s[i].total / 3.0;
    }

    // Display result
    printf("\nRoll No\tName\tSubject1\tSubject2\tSubject3\tTotal\tPercentage\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t%.2f\n",
               s[i].roll, s[i].name, s[i].m1, s[i].m2, s[i].m3,
               s[i].total, s[i].percentage);
    }

    return 0;
}
