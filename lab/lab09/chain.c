#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// Define the structure of the hash table
typedef struct
{
    node *head;
    int count;
} hash_bucket;

// Hash table array
hash_bucket *hashtable;

// The size of the hash table
int table_size;

// Hash function
int hash(int key)
{
    return key % table_size;
}

// Insert a value into the hash table
void insert(int value)
{
    int index = hash(value);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (hashtable[index].head == NULL)
    {
        hashtable[index].head = new_node;
    }
    else
    {
        node *current_node = hashtable[index].head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    hashtable[index].count++;
}

// Print the hash table
void print_table()
{
    printf("\n");
    for (int i = 0; i < table_size; i++)
    {
        printf("Chain[%d] -> ", i);
        node *current_node = hashtable[i].head;
        while (current_node != NULL)
        {
            printf("%d -> ", current_node->data);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    printf("\nInput the size of hash table: ");
    scanf("%d", &table_size);
    if (table_size < 1)
    {
        printf("The table size is not valid\n");
        return 0;
    }
    
    hashtable = (hash_bucket *)malloc(table_size * sizeof(hash_bucket));

    // Initialize the hash table array
    for (int i = 0; i < table_size; i++)
    {
        hashtable[i].head = NULL;
        hashtable[i].count = 0;
    }

    // Insert into the hash table
    int n;
    printf("\nInput the number of values to insert: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("The number is not valid\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d value:\n", i+1);
        int value;
        scanf("%d", &value);
        if (value < 0)
        {
            printf("Negative values are not allowed\n");
            continue;
        }
        insert(value);
    }

    // Print the hash table
    printf("\nHash Table: ");
    print_table();

    // Free the memory
    for (int i = 0; i < table_size; i++)
    {
        node *current_node = hashtable[i].head;
        while (current_node != NULL)
        {
            node *temp_node = current_node;
            current_node = current_node->next;
            free(temp_node);
        }
    }
    free(hashtable);

    return 0;
}
