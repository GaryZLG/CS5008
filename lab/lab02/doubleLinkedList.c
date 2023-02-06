#include <stdio.h>
#include <stdlib.h>

typedef struct dlist
{
    struct dlist *pre;
    int data;
    struct dlist *next;
} dlist_t;

void freeNode(dlist_t *node)
{
    if (node == NULL)
    {
        return;
    }
    free(node);
}

dlist_t *initdoubleLinkedList()
{
    dlist_t *head = (dlist_t *)malloc(sizeof(dlist_t));

    int number;
    printf("Please input the number of nodes you want to store in the LikedList:\n(better lager than 3 nodes)");
    scanf("%d", &number);

    if(number<1){
        printf("Empty linked list");
        return NULL;
    }

    int d;
    printf("Node 1:\n");
    scanf("%d", &d);

    head->pre = NULL;
    head->data = d;
    head->next = NULL;
    dlist_t *temp = head;
    if (number > 1)
    {
        for (int i = 2; i <= number; i++)
        {
            dlist_t *newNode = (dlist_t *)malloc(sizeof(dlist_t));

            int element;
            printf("Node %d:\n", i);
            scanf("%d", &element);

            temp->next = newNode;
            newNode->pre = temp;
            newNode->data = element;
            newNode->next = NULL;

            temp = temp->next;
        }
    }
    return head;
}

int searchPos(dlist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list!\n");
        return -1;
    }
    dlist_t *temp = head;
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

dlist_t *insertHead(dlist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }
    dlist_t *temp = head;

    dlist_t *newNode = (dlist_t *)malloc(sizeof(dlist_t));

    newNode->pre = NULL;
    newNode->data = element;
    newNode->next = temp;
    temp->pre = newNode;
    head = newNode;
    return head;
}

dlist_t *insertMiddle(dlist_t *head, int element, int position)
{
    if (position < 2 || head == NULL)
    {
        printf("Insert failed\n");
        return NULL;
    }

    dlist_t *temp = head;
    for (int i = 1; i < (position - 1); i++)
    {
        if (temp == NULL)
        {
            printf("Cannot find the position\n");
        }
        temp = temp->next;
    }

    // initiate new node
    dlist_t *newNode = (dlist_t *)malloc(sizeof(dlist_t));
    newNode->data = element;
    newNode->next = temp->next;
    newNode->pre = temp;

    temp->next->pre = newNode;
    temp->next = newNode;
    return head;
}

dlist_t *insertLast(dlist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty liked list\n");
        return NULL;
    }
    dlist_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    dlist_t *newNode = (dlist_t *)malloc(sizeof(dlist_t));
    newNode->data = element;
    newNode->next = NULL;
    newNode->pre = temp;
    temp->next = newNode;

    return head;
}

dlist_t *deleteHead(dlist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }
    else if (head->next == NULL && head->pre == NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }

    dlist_t *temp = head;

    temp->next->pre = NULL;
    head = temp->next;
    freeNode(temp);
    return head;
}

dlist_t *deleteLast(dlist_t *head)
{
    if (head == NULL)
    {
        printf("Empty liked list\n");
        return NULL;
    }
    else if (head->next == NULL && head->pre == NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }

    dlist_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->pre->next = NULL;
    freeNode(temp);
    return head;
}

dlist_t *deleteMiddle(dlist_t *head, int element)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }else if (head->next==NULL && head->pre==NULL)
    {
        freeNode(head);
        printf("Nothing left in the linked list!");
        return NULL;
    }
    
    dlist_t *temp = head;

    while (temp->data != element && temp->next != NULL)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("Cannot find the element. Delete failed.\n");
            return head;
        }
    }

    if (temp->pre == NULL)
    {
        head=deleteHead(head);
    }
    else if (temp->next == NULL)
    {
        head=deleteLast(head);
    }
    else
    {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;

        freeNode(temp);
    }

    return head;
}

void freeSList(dlist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list!");
        return;
    }
    dlist_t *itr = head;
    while (itr != NULL)
    {
        dlist_t *temp = itr;
        itr = itr->next;
        freeNode(temp);
    }
}

void inOrderPrintLinkedlist(dlist_t *head)
{
    if(head==NULL){
        printf("Empty linked list!");
        return;
    }
    dlist_t *itr = head;
    while (itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void reverseOrderPrint(dlist_t *head)
{
    if (head == NULL)
    {
        printf("Empty linked list!");
        return;
    }
    dlist_t *itr = head;
    while (itr->next != NULL)
    {
        itr = itr->next;
    }

    while (itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->pre;
    }

    printf("\n");
}

int main()
{
    printf("--------Double linked list manipulation--------\n");
    dlist_t *head = initdoubleLinkedList();
    printf("In order print: ");
    inOrderPrintLinkedlist(head);
    printf("Reverse order print: ");
    reverseOrderPrint(head);
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
        inOrderPrintLinkedlist(head);
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
            inOrderPrintLinkedlist(head);
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
            inOrderPrintLinkedlist(head);
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
            inOrderPrintLinkedlist(head);
            printf("\n");
            break;
        }
        case 4:
        {
            head = deleteHead(head);
            printf("Linkedlist after delete:");
            inOrderPrintLinkedlist(head);
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
            inOrderPrintLinkedlist(head);
            printf("\n");
            break;
        }
        case 6:
        {
            head = deleteLast(head);
            printf("Linkedlist after delete:");
            inOrderPrintLinkedlist(head);
            printf("\n");
            break;
        }
        case 7:
        {
            int e;
            printf("Input the element you search for:");
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
            printf("In order print: ");
            inOrderPrintLinkedlist(head);
            printf("Reverse order print: ");
            reverseOrderPrint(head);
            printf("\n");
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
