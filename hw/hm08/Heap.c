#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Swap
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Max heap
void MaxHeapify(int *h, int index, int length){
    int l = 2 * index;
    int r = 2 * index + 1;
    int max = index;

    if(l <= length && h[l] > h[max]){
        max = l;
    }

    if(r <= length && h[r] > h[max]){
        max = r;
    }

    if(max != index){
        swap(&h[index], &h[max]);
        MaxHeapify(h, max, length);
    }
}

void initMaxHeap(int *h, int length){
    for (int i = floor(length/2); i > 0; i--)
    {
        MaxHeapify(h, i, length);
    }
}

int RemoveMax(int *h, int *length){
    if (*length < 1)
    {
        printf("Heap underflow!\n");
        return -1;
    }
    int max = h[1];
    h[1] = h[*length];
    *length = *length - 1;
    MaxHeapify(h, 1, *length);
    return max;
}

//Min heap
void MinHeapify(int *h, int index, int length)
{
    int l = 2 * index;
    int r = 2 * index + 1;
    int min = index;

    if (l <= length && h[l] < h[min])
    {
        min = l;
    }

    if (r <= length && h[r] < h[min])
    {
        min = r;
    }

    if (min != index)
    {
        swap(&h[index], &h[min]);
        MinHeapify(h, min, length);
    }
}

void initMinHeap(int *h, int length)
{
    for (int i = floor(length / 2); i > 0; i--)
    {
        MinHeapify(h, i, length);
    }
}

int RemoveMin(int *h, int *length)
{
    if (*length < 1)
    {
        printf("Heap underflow!\n");
        return -1;
    }
    int min = h[1];
    h[1] = h[*length];
    *length = *length - 1;
    MinHeapify(h, 1, *length);
    return min;
}

void printArray(int *num, int size){
    if (num == NULL)
    {
        printf("The array is empty!");
        return;
    }

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", num[i]);
    }
}

int main(){

    //Input an array
    printf("Please input the number of integers: ");
    int size;
    scanf("%d", &size);

    if (size == 0 || size == 1)
    {
        printf("The array is too short to build heap");
        return 0;
    }
    
    int *num = (int *)malloc(sizeof(int) * (size+1));
    int *numMin = (int *)malloc(sizeof(int) * (size + 1));

    for (int i = 1; i <=size ; i++)
    {
        printf("Please input the %d integer: ", i);
        int temp;
        scanf("%d", &temp);
        num[i] = temp;
        numMin[i] = temp;
    }

    printf("The original array: ");
    printArray(num, size);
    printf("\n\n");

    //Build max heap
    initMaxHeap(num, size);
    printf("The Max heap array: ");
    printArray(num, size);
    printf("\n");

    //Max heap sort
    int *deArray = (int *)malloc(sizeof(int) * (size + 1));
    int tempSize1 = size;

    for (int i = 1; i <= size; i++)
    {
        deArray[i] = RemoveMax(num, &tempSize1);
    }
    printf("The descending sort array: ");
    printArray(deArray, size);
    printf("\n\n");

    

    // Build min heap
    initMinHeap(numMin, size);
    printf("The Min heap array: ");
    printArray(numMin, size);
    printf("\n");

    //Min heap sort
    int *asArray = (int *)malloc(sizeof(int) * (size + 1));
    int tempSize2 = size;

    for (int i = 1; i <= size; i++)
    {
        asArray[i] = RemoveMin(numMin, &tempSize2);
    }
    printf("The ascending sort array: ");
    printArray(asArray, size);
    printf("\n");

    free(deArray);
    free(asArray);
    free(num);
    free(numMin);
    return 0;
}