#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char stack[100];
int top = -1;

bool isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (top >= 99)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char c)
{
    if (!isFull())
    {
        top++;
        stack[top] = c;
    }
    else
    {
        // printf("Trying to push, but stack is full\n");
        return;
    }
}

char pop()
{
    char c = '\0';
    if (!isEmpty())
    {
        c = stack[top];
        top--;
    }
    // printf("Trying to pop, but stack is empty\n");
    return c;
}

bool checkValid(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char b = s[i];
        if (b == '(' || b == '[' || b == '{')
        {
            push(b);
        }
        else if (b == ')' || b == '}' || b == ']')
        {
            char check = pop();
            int temp = b - check;
            // ASCII transfer
            if (!(temp == 1 || temp == 2))
            {
                printf("The brackets string is Invalid.\n\n");
                return false;
            }
        }
        else
        {
            printf("Invalid input!");
            return false;
        }
    }
    return true;
}

int main()
{
    char *bracketString = (char *)malloc(sizeof(char) * 20);
    printf("\n");
    printf("Please input the brackets string: ");
    scanf("%s", bracketString);

    if (bracketString == NULL)
    {
        printf("Your inpute is NULL");
        free(bracketString);
        return 0;
    }

    if (checkValid(bracketString))
    {
        if (isEmpty())
        {
            printf("The string is Valid.\n\n");
        }
        else
        {
            printf("The brackets string is Invalid.\n\n");
        }
    }
    free(bracketString);

    return 0;
}