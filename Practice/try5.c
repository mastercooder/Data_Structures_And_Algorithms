#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* head)
{
    struct Node* ptr = head;
    do
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node* insertionAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data = data;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
};

struct Node* insertionAfterNode(struct Node* head, struct Node* prevNode, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
};


int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;
    struct Node* fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = fifth;

    fifth->data = 5;
    fifth->next = head;

    printf("\n");
    printf(" Linked List Traversal\n");
    printf("-----------------------\n");
    linkedListTraversal(head);

    printf("\n");
    printf(" After Insertion\n");
    printf("------------------\n");
    int data;
    char prevNode[10];
    printf("\n");
    printf("Enter the previous Node: \n");
    scanf("%s", prevNode);
    printf("Enter data: \n");
    scanf("%d", &data);
    head = insertionAfterNode(head, prevNode, data);
    linkedListTraversal(head);

    return 0;
}
