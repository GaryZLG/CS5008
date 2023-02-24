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

        while ((j >= 0) && (num[j] > temp))
        {
            num[j + 1] = num[j];
            num[j] = temp;
            j--;
            
        }
    }
}

int BinarySearch(int *num, int s, int target)
{
    InsertSort(num, s);
    int low = 0;
    int high = s - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if(num[mid] < target){
            low = mid + 1;
        }else if(num[mid]>target){
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
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

    // 3. Binary Search
    int r = BinarySearch(n, s, target);

    // 4. Print the search result
    printf("Search result:\n%d\n", r);

    return 0;
}