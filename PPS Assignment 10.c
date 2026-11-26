#include <stdio.h>

// Function to check leap year
int isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// Function to find the first day of the year (0 = Sunday, 1 = Monday, ... 6 = Saturday)
int firstDayOfYear(int year)
{
    int y = year - 1;
    return (1 + 5 * (y % 4) + 4 * (y % 100) + 6 * (y % 400)) % 7;
}

int main()
{
    int year, month, day, i;
    int startDay;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *monthName[12] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    printf("Enter the year: ");
    scanf("%d", &year);

    // Adjust February for leap year
    if (isLeap(year))
        daysInMonth[1] = 29;

    // Find the weekday of 1st January
    startDay = firstDayOfYear(year);

    for (month = 0; month < 12; month++)
    {
        printf("\n\n   ---------- %s %d ----------\n", monthName[month], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print spaces before the first day of the month
        for (i = 0; i < startDay; i++)
            printf("     ");

        // Print all days of the month
        for (day = 1; day <= daysInMonth[month]; day++)
        {
            printf("%5d", day);

            startDay++;
            if (startDay == 7)
            {
                printf("\n");
                startDay = 0;
            }
        }
    }

    printf("\n");
    return 0;
}
