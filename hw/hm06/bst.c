#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

node *initBST(node *root, int val)
{

    if (root == NULL)
    {
        root = makeNode(val);
    }
    else
    {
        if (root->data == val)
        {
            return root;
        }
        else
        {
            if (val > root->data)
            {
                root->right = initBST(root->right, val);
            }
            else
            {
                root->left = initBST(root->left, val);
            }
        }
    }
    return root;
}

int searchClosest(node *root, double target)
{

    double min = fabs(root->data - target);
    int result = root->data;
    node *temp = root;

    while (temp != NULL)
    {
        if (target < temp->data)
        {
            temp = temp->left;
            if (temp == NULL)
            {
                return result;
            }
            double ld = fabs(temp->data - target);
            if (ld < min)
            {
                min = ld;
                result = temp->data;
            }
        }
        else if (target > temp->data)
        {
            temp = temp->right;
            if (temp == NULL)
            {
                return result;
            }
            double rd = fabs(temp->data - target);
            if (rd < min)
            {
                min = rd;
                result = temp->data;
            }
        }
        else
        {
            return temp->data;
        }
    }
}

void inOrder(node *n)
{
    if (n == NULL)
    {
        return;
    }
    inOrder(n->left);
    printf("%d ", n->data);
    inOrder(n->right);
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
    node *root = NULL;
    printf("Input the number of nodes in your BST: ");
    int n;
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Input the %d value: ", i + 1);
        int val;
        scanf("%d", &val);

        root = initBST(root, val);
    }
    printf("InOrder print: \n");
    inOrder(root);

    printf("\nInput the target doubel: ");
    double val;
    scanf("%lf", &val);
    int r = searchClosest(root, val);
    printf("The closest node in the tree is: %d", r);

    freeTree(root);

    return 0;
}