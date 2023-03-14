#include <stdio.h>
#include <stdlib.h>
int front, rear;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *makeNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void enQueue(node *n[], node *Node)
{
    n[rear++] = Node;
}

node *deQueue(node *n[])
{
    return n[front++];
}

void freeTree(node *n)
{
    if (n->left != NULL)
    {
        freeTree(n->left);
        n->left = NULL;
    }
    if (n->right != NULL)
    {
        freeTree(n->right);
        n->right = NULL;
    }
    free(n);
}

int main()
{

    node *tree[15];

//Construct the tree
    for (int i = 0; i < 15; i++)
    {
        tree[i] = makeNode(i + 1);
    }

    for (int j = 0; j < 7; j++)
    {
        tree[j]->left = tree[2 * j + 1];
        tree[j]->right = tree[2 * j + 2];
    }

    // Initialize a queue
    node *q[20];
    node *temp;
    enQueue(q, tree[0]);

    printf("Breadth first search: \n");
    while (front < rear)
    {
        temp = deQueue(q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
        {
            enQueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            enQueue(q, temp->right);
        }
    }

    freeTree(tree[0]);
    return 0;
}
