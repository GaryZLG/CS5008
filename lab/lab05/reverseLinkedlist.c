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


slist_t *initSingleLinkedList()
{
    slist_t *head = NULL;
    slist_t *temp = (slist_t *)malloc(sizeof(slist_t));

    int number;
    printf("Please input the number of nodes you want to store in the LikedList:\n)");
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

slist_t * reverseList(slist_t *head){

    if(head ==NULL || head->next == NULL){
        return head;
    }else{
        slist_t *newHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

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
    printf("--------Single linked list reverse--------\n");
    slist_t *head = initSingleLinkedList();
    printf("In order print: ");
    printLinkedlist(head);
    printf("\n");
    printf("Recursively reverse the linked list: ");
    printLinkedlist(reverseList(head));
    
    freeSList(head);
    return 0;
}
