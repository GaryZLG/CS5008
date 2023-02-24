#include <stdio.h>
#include <stdlib.h>

void print(int *num, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

// Merge sort
void MergeSort(int num[], int size)
{
    int *a = num;
    int *b = (int *)malloc(size * sizeof(int));
    int divide, start;
    for (divide = 1; divide < size; divide += divide)
    {
        for (start = 0; start < size; start += divide * 2)
        {
            int mid = min(divide + start, size);
            int end = min(start + divide * 2, size);

            int k = start; // index of array b

            int start1 = start, end1 = mid;
            int start2 = mid, end2 = end;
            while (start1 < end1 && start2 < end2)
            {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }

            while (start1 < end1)
            {
                b[k++] = a[start1++];
            }

            while (start2 < end2)
            {
                b[k++] = a[start2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }

    if (a != num)
    {
        for (int i = 0; i < size; i++)
            b[i] = a[i];
        b = a;
    }
    
    free(b);
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
    MergeSort(n, s);
    print(n, s);

    return 0;
}