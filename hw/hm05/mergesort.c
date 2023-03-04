#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

// Merge sort
void MergeSort(int num[], int div[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    MergeSort(num, div, start1, end1);
    MergeSort(num, div, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
    {
        div[k++] = num[start1] < num[start2] ? num[start1++] : num[start2++];
    }

    while (start1 <= end1)
    {
        div[k++] = num[start1++];
    }

    while (start2 <= end2)
    {
        div[k++] = num[start2++];
    }

    for (k = start; k <= end; k++)
    {
        num[k] = div[k];
    }
}

void recursiveMergeSort(int num[], const int len)
{
    int div[len];
    MergeSort(num, div, 0, len - 1);
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
    recursiveMergeSort(n, s);
    print(n, s);

    return 0;
}