// Part B: Calculator

// Design a calculator which has functions for every operation. Let the user choose the operation.
// Use a switch case for the choice of operation to call the respective functions.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void multiplication(double *a, double *b)
{
    double r = *a * *b;
    printf("The result is: %f\n", r);
}

void division(double *a, double *b)
{
    double r = *a / *b;
    printf("The result is: %f\n", r);
}

void sum(double *a, double *b)
{
    double r = *a + *b;
    printf("The result is: %f\n", r);
}

void subtraction(double *a, double *b)
{
    double r = *a - *b;
    printf("The result is is: %f\n", r);
}

int main()
{
    while (1)
    {
        double a, b;
        int s;
        printf("Please select:\n");
        printf("1. Addition\n2. Substraction\n3. Multiplication\n4. Division\n5. Exit\n");

        scanf("%d", &s);
        if (s == 5)
        {
            exit(0);
        }

        printf("Input the first number:");
        scanf("%lf", &a);
        printf("Input the second number:");
        scanf("%lf", &b);

        switch (s)
        {
        case 1:
            sum(&a, &b);
            printf("\n");
            break;

        case 2:
            subtraction(&a, &b);
            printf("\n");
            break;

        case 3:
            multiplication(&a, &b);
            printf("\n");
            break;

        case 4:
            division(&a, &b);
            printf("\n");
            break;

        default:
            printf("Invalid input!\n");
            break;
        }
    }

    return 0;
}