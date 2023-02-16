#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

// Selection sort
void SelectionSort(int *num, int n)
{

    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }
        int temp = num[i];
        num[i] = num[min];
        num[min] = temp;

        print(num, n);
        printf("\n");
    }
}

int main()
{
    int s;
    printf("Input array size: ");
    scanf("%d", &s);

    int n[s];
    printf("Input element of array: \n");
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &n[i]);
    }

    printf("Original array: \n");
    print(n, s);
    printf("\n");

    printf("Sorting Process: \n");
    SelectionSort(n, s);
    printf("\n");

    printf("Sorted array: \n");
    print(n, s);

    return 0;
}