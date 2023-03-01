#include<stdio.h>

int factorial(int num){
    if (num>0)
    {
        return num * factorial(num - 1);
    }else if (num==0)
    {
        return 1;
    }else{
        printf("Negative integer has no factorial");
        return -1;
    }
    
    
}

int main(){
    printf("Please input an integer to calculate its factorial: \n");
    int num;
    scanf("%d", &num);
    printf("Factorial of %d is: %d\n", num, factorial(num));
    return 0;
}