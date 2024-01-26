#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertinFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
};

struct Node *insertinIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - i)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

struct Node *insertinEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr->next;
    ptr->next = NULL;
    return head;
};

struct Node *insertafterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    int query;
    printf("\n");
    printf(" Linked List Traversal\n");
    printf("--------------------------\n");
    linkedListTraversal(head);
    printf("\n");
    printf("\n");
    printf("i) Insert In First\n");
    printf("ii) Insert In Index\n");
    printf("iii) Insert In End\n");
    printf("iv) Insert After A Node\n");
    printf("Enter the operation you want to perform\n");
    scanf("%d", &query);
    printf("\n");

    switch (query)
    {
    case 1:
    {
        printf("\n");
        printf(" Insert In First\n");
        printf("-----------------\n");
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        head = insertinFirst(head, data);
        linkedListTraversal(head);
        break;
    }

    case 2:
    {
        printf("\n");
        printf(" Insert In Index\n");
        printf("------------------\n");
        int index, data;
        printf("Enter the data: ");
        scanf("%d", &data);
        printf("Enter the index: ");
        scanf("%d", &index);
        head = insertinIndex(head, index, data);
        linkedListTraversal(head);
        break;
    }

    default:
        printf("Something Went Wrong\n");
        break;
    }
}
