#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 9

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

int Dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return -1;
    }
    int r = q->data[++q->front];

    q->front %= MAXSIZE;
    q->size--;
    return r;
}

int main()
{
    // initiate the graph in matrix
    int matrixG[9][9] = {0};
    matrixG[0][1] = 1;
    matrixG[0][3] = 1;
    matrixG[1][2] = 1;
    matrixG[1][4] = 1;
    matrixG[2][5] = 1;
    matrixG[3][4] = 1;
    matrixG[3][6] = 1;
    matrixG[4][7] = 1;
    matrixG[5][8] = 1;
    matrixG[6][7] = 1;
    matrixG[7][8] = 1;

    printf("\n");

    // intiate queue
    Queue *q = initQueue();
    Enqueue(q, 0);

    // Set up an array to deal with visited node
    int seen[MAXSIZE] = {0};
    seen[0] = 1;

    printf("The breadth first search of the graph: \n");
    for (int i = 0; i < MAXSIZE; i++)
    {
        int temp = Dequeue(q);
        printf("%d ", temp);

        for (int j = 0; j < MAXSIZE; j++)
        {
            if (seen[j] == 0 && matrixG[temp][j] == 1)
            {
                Enqueue(q, j);
                seen[j] = 1;
            }
        }
    }

    free(q);
    return 0;
}