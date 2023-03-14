#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
//Construct the tree
node *makeNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(node *n)
{
    if (n != NULL)
    {
        printf("%d ", n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
    return;
}

void inOrder(node *n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
    return;
}

void postOrder(node *n)
{
    if (n != NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        printf("%d ", n->data);
    }
    return;
}

void freeTree(node *n)
{
    if (n->left != NULL)
    {
        freeTree(n->left);
    }
    if (n->right != NULL)
    {
        freeTree(n->right);
    }
    free(n);
}

int main()
{
    node *root;
    node *tree[15];

    for (int i = 0; i < 15; i++)
    {
        tree[i] = makeNode(i + 1);
    }

    for (int j = 0; j < 7; j++)
    {
        tree[j]->left = tree[2 * j + 1];
        tree[j]->right = tree[2 * j + 2];
    }
    root = tree[0];

    printf("Pre-Order: \n");
    preOrder(root);
    printf("\n");

    printf("In-Order: \n");
    inOrder(root);
    printf("\n");

    printf("Post-Order: \n");
    postOrder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
