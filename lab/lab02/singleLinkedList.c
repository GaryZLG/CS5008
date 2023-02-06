#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} slist_t;

void freeNode(slist_t *node)
{
    if (node == NULL)
    {
        return;
    }
    free(node);
}

int searchPos(slist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list!\n");
        return -1;
    }
    slist_t *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return pos;
            break;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

slist_t *insertHead(slist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }
    slist_t *temp = head;

    slist_t *newNode = (slist_t *)malloc(sizeof(slist_t));
    newNode->data = element;
    newNode->next = temp;
    head = newNode;
    return head;
}

slist_t *insertMiddle(slist_t *head, int element, int position)
{
    if (position < 2 || head == NULL)
    {
        printf("Insert failed\n");
        return NULL;
    }

    slist_t *temp = head;
    for (int i = 1; i < (position - 1); i++)
    {
        if (temp == NULL)
        {
            printf("Cannot find the position\n");
        }
        temp = temp->next;
    }

    // initiate new node
    slist_t *newNode = (slist_t *)malloc(sizeof(slist_t));
    newNode->data = element;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

slist_t *insertLast(slist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty liked list\n");
        return NULL;
    }
    slist_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    slist_t *newNode = (slist_t *)malloc(sizeof(slist_t));
    newNode->data = element;
    newNode->next = NULL;

    temp->next = newNode;
    return head;
}

slist_t *deleteHead(slist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }
    slist_t *temp = head;

    head = temp->next;
    freeNode(temp);
    return head;
}

slist_t *deleteMiddle(slist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }

    slist_t *temp = head;

    while (temp->next->data != element && temp->next != NULL)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("Cannot find the element\n");
            return head;
        }
    }

    slist_t *del = temp->next;
    temp->next = temp->next->next;
    freeNode(del);
    return head;
}

slist_t *deleteLast(slist_t *head)
{
    if (head == NULL)
    {
        printf("Empty liked list\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }
    slist_t *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    slist_t *del = temp->next;
    temp->next = NULL;
    freeNode(del);
    return head;
}

slist_t *initSingleLinkedList()
{
    slist_t *head = NULL;
    slist_t *temp = (slist_t *)malloc(sizeof(slist_t));

    int number;
    printf("Please input the number of nodes you want to store in the LikedList:\n(better lager than 3 nodes)");
    scanf("%d", &number);
    if (number < 1)
    {
        printf("Empty linked list");
        return NULL;
    }

    int d;
    printf("Node 1:\n");
    scanf("%d", &d);

    temp->data = d;
    temp->next = NULL;
    head = temp;
    if (number > 1)
    {
        for (int i = 2; i <= number; i++)
        {
            slist_t *newNode = (slist_t *)malloc(sizeof(slist_t));

            int element;
            printf("Node %d:\n", i);
            scanf("%d", &element);

            newNode->data = element;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void freeSList(slist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list!");
        return;
    }
    slist_t *itr = head;
    while (itr != NULL)
    {
        slist_t *temp = itr;
        itr = itr->next;
        freeNode(temp);
    }
}

void printLinkedlist(slist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list!");
        return;
    }
    slist_t *itr = head;
    while (itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

int main()
{
    printf("--------Single linked list manipulation--------\n");
    slist_t *head = initSingleLinkedList();
    printf("In order print: ");
    printLinkedlist(head);
    printf("\n");
    printf("-----------------------------------------------\n");

    while (1)
    {
        int select;
        printf("1. Insert at the head\n2. Insert in the middle\n3. Insert at the end\n");
        printf("4. Delete the head\n5. Delete from the middle\n6. Delete the end\n");
        printf("7. Search an element\n8. Print and Exit\n");
        printf("-----------------------------------------------\n");
        printf("The current linked list: ");
        printLinkedlist(head);
        printf("\n");
        printf("Please select the action:");

        scanf("%d", &select);
        switch (select)
        {
        case 1:
        {
            int d;
            printf("Please input the added data:");
            scanf("%d", &d);
            head = insertHead(head, d);
            printf("Linkedlist after insert:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 2:
        {
            int d;
            printf("Please input the added data:");
            scanf("%d", &d);
            int p;
            printf("Please input the added position:");
            scanf("%d", &p);
            head = insertMiddle(head, d, p);
            printf("Linkedlist after insert:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 3:
        {
            int d;
            printf("Please input the added data:");
            scanf("%d", &d);
            head = insertLast(head, d);
            printf("Linkedlist after insert:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 4:
        {
            head = deleteHead(head);
            printf("Linkedlist after delete:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 5:
        {
            int d;
            printf("Please input the delete data:");
            scanf("%d", &d);
            head = deleteMiddle(head, d);
            printf("Linkedlist after delete:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 6:
        {
            head = deleteLast(head);
            printf("Linkedlist after delete:");
            printLinkedlist(head);
            printf("\n");
            break;
        }
        case 7:
        {
            int e;
            printf("Input the element you search for:\n");
            scanf("%d", &e);
            int r = searchPos(head, e);
            if (r < 0)
            {
                printf("Cannot find the element\n");
            }
            else
            {
                printf("The element you search is at the position: %d\n", r);
            }
            break;
        }
        case 8:
            printLinkedlist(head);
            printf("--------------End--------------\n");
            freeSList(head);
            exit(0);
        default:
            printf("Invalid input!");
            break;
        }
    }
    freeSList(head);
    return 0;
}
