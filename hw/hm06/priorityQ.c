#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
    int data;
    int priority;
    struct Node *nextNode;
} Node;

Node *headNode = NULL;
int size = 0;

void Enqueue(int value, int priority)
{
    if (size == MAX_SIZE)
    {
        printf("Priority Queue is full. Cannot enqueue more elements.\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->nextNode = NULL;
    if (headNode == NULL || priority < headNode->priority)
    {
        newNode->nextNode = headNode;
        headNode = newNode;
    }
    else
    {
        Node *currentNode = headNode;
        do
        {
            if (currentNode->nextNode == NULL || currentNode->nextNode->priority > priority)
            {
                newNode->nextNode = currentNode->nextNode;
                currentNode->nextNode = newNode;
                break;
            }
            currentNode = currentNode->nextNode;
        } while (currentNode != NULL);
    }
    size++;
}

void Dequeue()
{
    if (headNode == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("%d with priority %d has been dequeued from the Priority Queue.\n", headNode->data, headNode->priority);
    headNode = headNode->nextNode;
    size--;
}

int isEmpty()
{
    if (headNode == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (size == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PrintQueue()
{
    if (headNode == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue:\n");
    Node *currentNode = headNode;
    while (currentNode != NULL)
    {
        printf("%d (Priority: %d)\n", currentNode->data, currentNode->priority);
        currentNode = currentNode->nextNode;
    }
}

void DestroyQueue()
{
    Node *currentNode = headNode;
    do
    {
        Node *tempNode = currentNode;
        currentNode = currentNode->nextNode;
        free(tempNode);
    } while (currentNode != NULL);
    headNode = NULL;
    size = 0;
    printf("Priority Queue has been destroyed.\n");
}

int main()
{
    int option, value, priority;
    do
    {
        printf("Choose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if the Priority Queue is empty\n");
        printf("4. Check if the Priority Queue is full\n");
        printf("5. Destroy the Priority Queue\n");
        printf("6. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter a value to be enqueued: ");
            scanf("%d", &value);
            printf("Enter the priority of the value: ");
            scanf("%d", &priority);
            Enqueue(value, priority);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            do
            {
                if (isEmpty())
                {
                    printf("Priority Queue is empty.\n");
                }
                else
                {
                    printf("Priority Queue is not empty.\n");
                }
                printf("Press any key to return to the main menu.\n");
            } while (getchar() != '\n');
            break;
        case 4:
            do
            {
                if (isFull())
                {
                    printf("Priority Queue is full.\n");
                }
                else
                {
                    printf("Priority Queue is not full.\n");
                }
                printf("Press any key to return to the main menu.\n");
            } while (getchar() != '\n');
            break;
        case 5:
            DestroyQueue();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
        }
    } while (1);
    return 0;
}
