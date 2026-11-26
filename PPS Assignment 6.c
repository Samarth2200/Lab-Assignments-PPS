#include <stdio.h>

// Function without recursion (using a loop)
int factorial_iterative(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

// Function with recursion (function calls itself)
int factorial_recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of number (without recursion) = %d\n", factorial_iterative(num));
        printf("Factorial of number (with recursion) = %d\n", factorial_recursive(num));
    }

    return 0;
}
