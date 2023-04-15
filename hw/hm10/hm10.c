#include<stdio.h>
#include<stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


void knapspack(int *weights, int *values, int itemNum, int weightCap){

    //create the dp 2d array
    int **dp = (int **)malloc(sizeof(int *) * itemNum);
    for (int i = 0; i < itemNum; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (weightCap + 1));
    }

    //initiate the array
    for (int i = 0; i < itemNum; i++)
    {
        for (int j = 0; j <= weightCap; j++)
        {
            dp[i][j] = 0;
        }
        
    }

    // first item with value
    for (int i = weights[0]; i <= weightCap; i++)
    {
        dp[0][i] = values[0];
    }

    //bottom to up to store the max value
    for (int i = 1; i < itemNum; i++)
    {
        for (int j = 1; j <= weightCap; j++)
        {
            if (weights[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            }
            
        }
        
    }

    /*for (int i = 0; i < itemNum; i++)
    {
        for (int j = 0; j <= weightCap; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    printf("The biggest value answer: %d\n", dp[itemNum - 1][weightCap]);

    for (int i = 0; i < itemNum; i++)
    {
        free(dp[i]);
    }
    free(dp);
}


int main(){

    int num;
    printf("\nInput the number of items: ");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("The item number cannot be non-positive!\n");
        return 0;
    }
    printf("\n");

    int *value = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        printf("Input the %d item value: ", i + 1);
        scanf("%d", &value[i]);
    }

    int *weight = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        printf("Input the %d item weight: ", i + 1);
        scanf("%d", &weight[i]);
    }

    int cap;
    printf("\nInput the Knapsack weight capacity: ");
    scanf("%d", &cap);

    knapspack(weight, value, num, cap);

    free(value);
    free(weight);
    return 0;
}