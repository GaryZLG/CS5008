#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct Q
{
    int data[MAXSIZE];
    int front;
    int end;
    int size;
} Queue;

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Heap memory is full!\n");
        return NULL;
    }
    q->front = -1;
    q->end = -1;
    q->size = 0;
    return q;
}

bool isFull(Queue *q)
{
    return (q->size == MAXSIZE);
}

bool isEmpty(Queue *q)
{
    return (q->size == 0);
}

void Enqueue(Queue *q, int n)
{
    if (isFull(q))
    {
        printf("The queue is full!\n");
        return;
    }
    q->end++;
    q->size++;
    q->end %= MAXSIZE;
    q->data[q->end] = n;
}

void Dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return;
    }
    q->front++;
    q->front %= MAXSIZE;
    q->size--;
}

int Peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return -99;
    }
    // 标记
    return q->data[(q->front + 1)];
}

void print(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty queue!\n");
        return;
    }
    printf("The current queue: ");
    int index = q->front;
    for (int i = 0; i < q->size; i++)
    {
        index++;
        index %= MAXSIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

int main()
{
    Queue *q = initQueue();

    while (1)
    {
        printf("\n");
        printf("1. Add en element to the queue\n");
        printf("2. Delete the element from the front\n");
        printf("3. Check empty\n");
        printf("4. Check full\n");
        printf("5. Peek the first element\n");
        printf("6. Exit\n");
        printf("Please selecet: ");

        int select;
        scanf("%d", &select);

        switch (select)
        {
        case 1:
        {
            int add;
            printf("Please input the integer you want to add:");
            scanf("%d", &add);
            Enqueue(q, add);
            print(q);
            printf("\n");
            break;
        }
        case 2:
        {
            Dequeue(q);
            print(q);
            printf("\n");
            break;
        }
        case 3:
        {
            if (isEmpty(q) == 1)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            print(q);
            printf("\n");
            break;
        }
        case 4:
        {
            if (isFull(q) == 0)
            {
                printf("false\n");
            }
            else
            {
                printf("true\n");
            }
            print(q);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("The first element is: %d\n", Peek(q));
            print(q);
            printf("\n");
            break;
        }
        case 6:
            print(q);
            free(q);
            exit(0);
        default:
            printf("Invalid input!\n");
            break;
        }
    }
    free(q);
    return 0;
}
