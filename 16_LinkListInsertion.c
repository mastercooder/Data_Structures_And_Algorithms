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

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->data = data;

    ptr->next = head;
    return ptr;
};

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node* p = head;
    
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

// Case 3
struct Node * insertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    head->data = 1;
    head->next = second;

    // Linked Second and Thrid
    second->data = 2;
    second->next = third;

    // Linked Thrid and Fourth
    third->data = 3;
    third->next = forth;

    // Terminate the List at the Third Node
    forth->data = 5;
    forth->next = NULL;

    printf(" Linked List Traversal\n");
    printf("-----------------------\n");
    linkedListTraversal(head);
    printf(" \n");

    printf("\n");
    printf("1: Insertion At First\n");
    printf("2: Insertion At Index\n");
    printf("3: Insertion At End\n");
    printf("4: Insertion After a Node\n");
    printf("\n");

    int query;


    while (1)
    {

        printf("Which function you want to execute || 0 to exit: \n");
        scanf("%d", &query);

        if(query==0)
        {
            printf("\n");
            printf("Exeting The Loop!\n");
            return -1;
            printf("\n");
        }

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Insertion At First\n");
                printf("------------------------\n");
                int value;
                printf("Enter the Value: ");
                scanf("%d", &value);
                head = insertAtFirst(head,  value);
                linkedListTraversal(head);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" Insertion At Index\n");
                printf("------------------------\n");
                int index, value;
                printf("Enter At which Index you want to endter value: \n");
                scanf("%d", &index);
                index -= 1;
                printf("Enter The value: \n");
                scanf("%d", &value);
                head = insertAtIndex(head, value, index);
                linkedListTraversal(head);
                printf("\n");
                break;
            }
            
            case 3:
            {
                printf("\n");
                printf("  Insert At End\n");
                printf("-------------------\n");
                int value;
                printf("Enter what you want to enter: \n");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                linkedListTraversal(head);
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" Insert After Node\n");
                printf("--------------------\n");
                int node, value;
                printf("Enter the Previous NOde: ");
                scanf("%d", &node);
                printf("Enter the value: \n");
                scanf("%d", &value);
                head = insertAfterNode(head, node, value);
                linkedListTraversal(head);
                printf("\n");

            }
            default:
                printf("Something went wrong\n");
                break;
            }
    }

    return 0;
}