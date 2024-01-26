#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

void linkedListTraversal(struct Node* ptr){
    while (ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->next = head;
    ptr->data = data; 
    return ptr;
};

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    
    int i = 0;
    while (i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;

    // Alocation memory for Node in Linked List in Heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    forth = (struct Node*) malloc(sizeof(struct Node));

    // Linked First and Second
    head->data = 7;
    head->next = second;

    // Linked Second and Thrid
    second->data = 11;
    second->next = third;

    // Linked Thrid and Fourth
    third->data = 66;
    third->next = forth;

    // Terminate the List at the Third Node
    forth->data = 77;
    forth->next = NULL;

    printf("Before Insercation\n");
    printf(" \n");
    linkedListTraversal(head);
    printf(" \n");
    printf("After Insercation\n");
    printf("\n");
    head = insertAtIndex(head, 3, 3);
    linkedListTraversal(head);
    printf("\n");
    return 0;
}