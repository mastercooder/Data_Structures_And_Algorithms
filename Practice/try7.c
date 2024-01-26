#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prevNode;
};

// void linkedListTravesral(struct Node* ptr)
// {
//     struct Node* head = ptr;
//     do
//     {
//         printf(" Previous Node: %d\n", (ptr->prevNode!=NULL)? ptr->prevNode->data:-1);
//         ptr = ptr->next;
//     } while (ptr!=head);
    
// }

void linkedListTravesral(struct Node* ptr)
{
    struct Node* head = ptr;
    while (ptr!=head)
    {
        printf(" Previous Node: %d\n", ptr->data); 
        ptr = ptr->next;
    } 
    
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
    linkedListTravesral(head);
    
    return 0;
}
