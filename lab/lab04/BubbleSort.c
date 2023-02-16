#include<stdio.h>
#include<stdlib.h>

void print(int *num, int s){

    for (int i = 0; i < s; i++)
    {
        printf("%d ", num[i]);
    }
    
}

//Bubble sort
void BubbleSort(int *num, int n){

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(num[j] > num[j+1]){
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
                print(num, n);
                printf("\n");
            } 
        }
    }
}

int main(){
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
    BubbleSort(n, s);
    printf("\n");

    printf("Sorted array: \n");
    print(n, s);


    return 0;
}