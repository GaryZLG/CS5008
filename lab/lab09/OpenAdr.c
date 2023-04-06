#include <stdio.h>
#include <stdlib.h>

#define MAXATTEMPT 100
int count;

// Linear probing
int linearProbe(int *table, int size, int value)
{
    int index = value % size;
    int i = 0;
    while (table[index] != -1 && i < size)
    {
        index = (index + 1) % size;
        i++;
    }

    if (i == size)
    {
        printf("Error: table is full; insertion failed.\n");
        return -1;
    }
    table[index] = value;
    count++;
    return index;
}

// Quadratic probing
int quadraticProbe(int *table, int size, int value)
{
    int index = value % size;
    int key = index;
    int i = 0;
    while (table[index] != -1 && i < MAXATTEMPT)
    {
        index = (key + i * i) % size;
        i++;
    }

    if (i == MAXATTEMPT)
    {
        printf("Failed to insert value %d after %d attempts.\n", value, MAXATTEMPT);
        return -1;
    }
    table[index] = value;
    count++;
    return index;
}

// Double hashing
int doubleHashing(int *table, int size, int value)
{
    int h1 = value % size;
    int h2 = 7 - (value % 7);
    int index = h1;
    int i = 0;
    while (table[index] != -1 && i < MAXATTEMPT)
    {
        index = (h1 + i * h2) % size;
        i++;
    }

    if (i == MAXATTEMPT)
    {
        printf("Error: failed to insert value %d after %d attempts.\n", value, MAXATTEMPT);
        return -1;
    }

    table[index] = value;
    count++;
    return index;
}

// Print the hash table
void printTable(int *table, int size)
{
    printf("Hash table:\n");
    for (int i = 0; i < size; i++)
    {
        if (table[i] == -1)
        {
            printf("Slot %d: NULL\n", i);
        }
        else
        {
            printf("Slot %d: %d\n", i, table[i]);
        }
    }
}

int main()
{
    int size, probeType;
    count = 0;

    // Get user input for table size
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    if (size < 1)
    {
        printf("Table size is invalid\n");
        return 0;
    }

    int *table = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }

    // Choose the probing type
    printf("\nChoose probing method:\n");
    printf("1. Linear probing\n");
    printf("2. Quadratic probing\n");
    printf("3. Double hashing\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &probeType);

    while (1)
    {
        int value;
        printf("\nEnter the value to insert (Enter negative integer to exit): ");
        scanf("%d", &value);

        if (value < 0)
        {
            printf("Program exits");
            free(table);
            exit(0);
        }
        else if (count == size)
        {
            printf("Table is full\n");
            printTable(table, size);
            free(table);
            exit(0);
        }

        switch (probeType)
        {
        case 1:
            linearProbe(table, size, value);
            printTable(table, size);
            break;
        case 2:
            quadraticProbe(table, size, value);
            printTable(table, size);
            break;
        case 3:
            doubleHashing(table, size, value);
            printTable(table, size);
            break;
        case 4:
            printf("Program exits");
            free(table);
            exit(0);
        default:
            printf("Invalid probing type.\n");
            free(table);
            return 0;
        }
    }

    return 0;
}
