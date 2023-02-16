#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

// Insert sort
void InsertSort(int *num, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = num[i];
        int j = i - 1;

        while((j>=0) && (num[j] > temp))
        {
            num[j + 1] = num[j];
            num[j] = temp;
            j--;
            print(num, n);
            printf("\n");
        }

        //num[j + 1] = temp;
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
    InsertSort(n, s);
    printf("\n");

    printf("Sorted array: \n");
    print(n, s);

    return 0;
}