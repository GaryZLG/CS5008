#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

// Quick sort
void QuickSort(int num[], int start, int end)
{
    if (start < end)
    {
        int i = start;
        int j = end - 1;
        int k = num[start];

        while (i < j)
        {
            while (i < j && num[j] >= k)
            {
                j--;
            }

            if (i < j)
            {
                num[i++] = num[j];
            }

            while (i < j && num[i] < k)
            {
                i++;
            }

            if (i < j)
            {
                num[j--] = num[i];
            }
        }
        num[i] = k;

        //Recursively call quick sort
        QuickSort(num, start, i);
        QuickSort(num, i + 1, end);
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

    printf("Sorted array: \n");
    QuickSort(n, 0, s);
    print(n, s);

    return 0;
}