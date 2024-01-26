#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prevNode;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    struct Node* head = ptr;  // Save the head node to terminate the loop
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node* insertionAtFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prevNode = head->prevNode;  // Update the prevNode to the previous last node
    ptr->next = head;
    head->prevNode->next = ptr;  // Update the next of the previous last node
    head->prevNode = ptr;  // Update the prevNode of the head
    return ptr;  // Return the new head
}

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
    head->prevNode = NULL;
    head->next = second;

    second->data = 2;
    second->prevNode = head;
    second->next = third;

    third->data = 3;
    third->prevNode = second;
    third->next = forth;

    forth->data = 4;
    forth->prevNode = third;
    forth->next = fifth;

    fifth->data = 5;
    fifth->prevNode = forth;
    fifth->next = head;

    printf("\n");
    printf(" Linked List Traversal\n");
    printf("------------------------\n");
    linkedListTraversal(head);

    return 0;
}
