#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
    
};

struct Node* insertionAtFirst(struct Node *head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return head;
};



int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    
    head = (struct Node*) malloc(sizeof(struct Node*)); 
    second = (struct Node*) malloc(sizeof(struct Node*)); 
    third = (struct Node*) malloc(sizeof(struct Node*)); 

    // First
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("\n");
    printf(" After Insercation\n");
    printf("-------------------- \n");
    head = insertionAtFirst(head, 1);
    linkedListTraversal(head);
    return 0;
}