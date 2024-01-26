// Make a linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Elements %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node insertionAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
    
};


int main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *thid = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = thid;

    thid->data = 3;
    thid->next = NULL;

    printf("\n");
    printf(" Printing Linked List\n");
    printf("-----------------------\n");
    linkedlistTraversal(head);

}
