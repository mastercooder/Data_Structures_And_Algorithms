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

    linkedListTraversal(head);

    return 0;
}