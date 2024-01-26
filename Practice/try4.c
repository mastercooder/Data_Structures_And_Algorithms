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
    }while (ptr!=head);
}

struct Node* insertionAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    ptr->data = data;
    ptr->next = head;

    if (head==NULL)
    {
        head==ptr;
    } 
    else
    {
        while (p->next!=head)
        {
            p = p->next;
        }
    }
    p->next = ptr;
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
    head = insertionAtEnd(head, 6);
    linkedListTraversal(head);
    return 0;
}



