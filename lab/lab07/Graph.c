#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *makeNode(int val, node *nextNode)
{
    node *n = (node *)malloc(sizeof(node));
    n->value = val;
    n->next = nextNode;
    return n;
}

void freeAdjList(node **adjList)
{
    for (int i = 0; i < 4; i++)
    {
        node *curr = adjList[i];
        while (curr != NULL)
        {
            node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adjList);
}

int main()
{
    // initiate the graph in matrix
    int matrixG[4][4] = {0};
    matrixG[0][1] = 1;
    matrixG[0][2] = 1;
    matrixG[1][2] = 1;
    matrixG[2][0] = 1;
    matrixG[3][2] = 1;

    // print the adjacency matrix
    printf("Adjacency Matrix: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrixG[i][j]);
        }
        printf("\n");
    }

    // convert the matrix to adacency list
    node **adjList = (node **)malloc(4 * sizeof(node*));
    for (int i = 0; i < 4; i++)
    {
        adjList[i] = NULL;
        for (int j = 0; j < 4; j++)
        {
            if (matrixG[i][j] == 1)
            {
                if (adjList[i] == NULL)
                {
                    adjList[i] = makeNode(j, NULL);
                }
                else
                {
                    node *temp = adjList[i];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    
                    temp->next = makeNode(j, NULL);
                }
            }
        }
    }

    printf("\n");
    printf("Adjacency list: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("Node %d: ", i);
        node *temp = adjList[i];
        for (int j = 0; j < 4; j++)
        {
            if (temp->next == NULL)
            {
                printf("%d -> Null\n", temp->value);
                break;
            }
            else
            {
                printf("%d -> ", temp->value);
                temp = temp->next;
            }
        }
    }

    freeAdjList(adjList);
    return 0;
}