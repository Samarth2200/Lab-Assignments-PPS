#include <stdio.h>

int main()
{
    int n, i;
    float distance[20];
    float *ptr;          // pointer to traverse the array
    float *nearest;      // pointer to the smallest distance
    float limit = 20.0;  // warning distance in cm

    printf("Enter the number of sensors: ");
    scanf("%d", &n);

    // Store distance readings from each sensor
    for (i = 0; i < n; i++)
    {
        printf("Enter distance reading of sensor %d (in cm): ", i + 1);
        scanf("%f", &distance[i]);
    }

    // Use pointers to find the nearest obstacle
    ptr = distance;
    nearest = distance;

    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) < *nearest)
        {
            nearest = ptr + i;
        }
    }

    // Display readings
    printf("\nSensor readings:\n");
    for (i = 0; i < n; i++)
    {
        printf("Sensor %d = %.2f cm\n", i + 1, *(ptr + i));
    }

    // Display nearest obstacle
    printf("\nNearest obstacle: Sensor %d at %.2f cm\n",
           (int)(nearest - distance) + 1, *nearest);

    // Warning if too close
    if (*nearest < limit)
    {
        printf("WARNING: Obstacle is too close!\n");
    }
    else
    {
        printf("Path is safe.\n");
    }

    return 0;
}
