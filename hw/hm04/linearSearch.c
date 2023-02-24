#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

void convertDToB(int *target)
{
    int temp = *target;
    int r[32];
    int count = 0;
    while (temp != 0)
    {
        r[count] = temp % 2;
        count++;
        temp = temp / 2;
    }

    int result = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        result = result * 10 + r[i];
    }
    *target = result;
}

int LinearSearch(int *num, int s, int target)
{
    for (int i = 0; i < s; ++i)
    {
        if (num[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void convertBtoD(int *target){
    int temp = *target;
    int r[32];
    int count = 0;
    while (temp != 0)
    {
        r[count] = temp % 10;
        count++;
        temp = temp / 10;
    }

    int result = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        result = result * 2 + r[i];
    }
    *target = result;
}

int main()
{
    // 1. Input array and target
    int s;
    printf("Input array size: ");
    scanf("%d", &s);
    if (s <= 0)
    {
        printf("Array size cannot be non-positive!\n");
        return 0;
    }

    int n[s];
    printf("Input element of array: \n");
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &n[i]);
        if (n[i] < 0)
        {
            printf("Data cannot be negative!\n");
            return 0;
        }
    }

    int target;
    printf("Input search target: ");
    scanf("%d", &target);

    // 2. Print array and target
    printf("The array: \n");
    print(n, s);
    printf("\n");
    printf("The target: \n%d\n", target);

    // 3. Convert integer to binary
    for (int i = 0; i < s; i++)
    {
        convertDToB(&n[i]);
    }
    convertDToB(&target);

    // 4. Print the converted array and target
    printf("Converted array: \n");
    print(n, s);
    printf("\n");
    printf("Converted target:\n%d\n", target);

    // 5. Linear Search
    int r = LinearSearch(n, s, target);

    //6. Print the search restult
    printf("Search result:\n%d\n", r);

    //7. Convert to the original array
    for (int i = 0; i < s; i++)
    {
        convertBtoD(&n[i]);
    }
    convertBtoD(&target);

    //8. Print the original ones
    printf("Original array: \n");
    print(n, s);
    printf("\n");
    printf("Original target:\n%d\n", target);

    return 0;
}