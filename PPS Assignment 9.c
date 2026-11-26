#include <stdio.h>

struct Record
{
    float depth;        // in meters
    float pressure;     // in bar
    float temperature;  // in degree Celsius
    int battery;        // in percentage
    int defects;        // number of structural defects detected
};

int main()
{
    struct Record r[50];
    int n, i;
    int unsafe, unsafeCount = 0;

    // Safe limits
    float maxDepth = 100.0;
    float maxPressure = 10.0;
    float maxTemp = 35.0;
    float minTemp = 2.0;
    int minBattery = 20;
    int maxDefects = 3;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    // Store robot data
    for (i = 0; i < n; i++)
    {
        printf("\nRecord %d\n", i + 1);
        printf("Enter depth (m): ");
        scanf("%f", &r[i].depth);
        printf("Enter water pressure (bar): ");
        scanf("%f", &r[i].pressure);
        printf("Enter temperature (C): ");
        scanf("%f", &r[i].temperature);
        printf("Enter battery percentage: ");
        scanf("%d", &r[i].battery);
        printf("Enter number of structural defects: ");
        scanf("%d", &r[i].defects);
    }

    // Process historical records and generate inspection report
    printf("\n========== INSPECTION REPORT ==========\n");

    for (i = 0; i < n; i++)
    {
        unsafe = 0;

        printf("\nRecord %d: Depth=%.1f m, Pressure=%.1f bar, Temp=%.1f C, Battery=%d%%, Defects=%d\n",
               i + 1, r[i].depth, r[i].pressure, r[i].temperature,
               r[i].battery, r[i].defects);

        if (r[i].depth > maxDepth)
        {
            printf("  WARNING: Depth exceeds safe limit!\n");
            unsafe = 1;
        }
        if (r[i].pressure > maxPressure)
        {
            printf("  WARNING: Water pressure too high!\n");
            unsafe = 1;
        }
        if (r[i].temperature > maxTemp || r[i].temperature < minTemp)
        {
            printf("  WARNING: Temperature out of safe range!\n");
            unsafe = 1;
        }
        if (r[i].battery < minBattery)
        {
            printf("  WARNING: Battery level low!\n");
            unsafe = 1;
        }
        if (r[i].defects > maxDefects)
        {
            printf("  WARNING: Too many structural defects!\n");
            unsafe = 1;
        }

        if (unsafe)
        {
            printf("  Status: UNSAFE\n");
            unsafeCount++;
        }
        else
        {
            printf("  Status: SAFE\n");
        }
    }

    printf("\n========== SUMMARY ==========\n");
    printf("Total records   : %d\n", n);
    printf("Unsafe records  : %d\n", unsafeCount);
    printf("Safe records    : %d\n", n - unsafeCount);

    return 0;
}
