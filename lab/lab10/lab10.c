#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int coinChange(int *coins, int size, int amount, int *memo){
    if (amount < 0 || coins == NULL)
    {
        return -1;
    }

    if (amount == 0)
    {
        return 0;
    }

    if (memo[amount - 1] != INT_MAX)
    {
        return memo[amount - 1];
    }

    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        int ans = coinChange(coins, size, amount - coins[i], memo);
        if (ans >= 0 && ans < min)
        {
            min = ans + 1;
        }
        
    }

    memo[amount - 1] = (min == INT_MAX) ? -1 : min;
    return memo[amount - 1];
}

int coinNum(int *coins, int size, int amount, int *memo){
    if (amount < 1)
    {
        return 0;
    }

    return coinChange(coins, size, amount, memo);
}


int main(){

    int size;
    printf("\nInput the number of coins: ");
    scanf("%d", &size);
    if (size <= 0 )
    {
        printf("The coins number cannot be non-positive!");
        return 0;
    }
    printf("\n");

    int *coins = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Input the %d coin value: ", i+1);
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("\nInput the amount: ");
    scanf("%d", &amount);

    int *dp = (int *)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }
    
    int res = coinNum(coins, size, amount, dp);
    printf("\nThe answer: %d\n", res);
    
    free(dp);
    free(coins);
    return 0;
}