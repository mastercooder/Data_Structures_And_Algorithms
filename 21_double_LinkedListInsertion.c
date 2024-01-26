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
    struct Node* head = ptr;
    do
    {
        printf("Element %d and Previous Node %d\n", ptr->data, (ptr->prevNode!=NULL)? ptr->prevNode->data: -1);
        ptr = ptr->next;
    } while (ptr!=head);
    
}

struct Node* insertionAtFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prevNode = head->prevNode;
    ptr->next = head;
    head->prevNode = ptr;
    return ptr;
};

struct Node* insertionAtIndex(struct Node* head, int data, int index)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data = data;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;    
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prevNode = p;
    ptr->next->prevNode = ptr;
    return head;
};

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
    ptr->prevNode = p;
    return head;
};

struct Node* insertionAfteNode(struct Node* head, struct Node* preNode, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = preNode->next;
    preNode->next = ptr;
    ptr->prevNode = preNode;
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

    printf("\n");
    printf("1. Insertion At First\n");
    printf("2. Insertion At Index\n");
    printf("3. Insertion At End\n");
    printf("4. Insertion After NOde\n");
    printf("\n");

    int query;
    printf("Enter the Number which Operation you want to persform: || 0 for Exit: \n");
    scanf("%d", &query);

    if(query==0)
    {
        printf("Exiting The Loop!\n");
        return -1;
    }
    switch (query)
    {
    case 1:
        {
            printf("\n");
            printf(" Insertion At First\n");
            printf("----------------------\n");
            int data;
            printf("Enter the data: \n");
            scanf("%d", &data);
            printf("-------------------------\n");
            head = insertionAtFirst(head, data);
            linkedListTraversal(head);
            printf("-------------------------\n");
            printf("\n");
            break;
        }
    
    case 2:
        {
            printf("\n");
            printf(" Insertion At Index\n");
            printf("----------------------\n");
            int data, index;
            printf("Enter the data: \n");
            scanf("%d", &data);
            printf("Enter the Index: \n");
            scanf("%d", &index);
            printf("-------------------------\n");
            head = insertionAtIndex(head, data, index);
            linkedListTraversal(head);
            printf("-------------------------\n");
            printf("\n");
            break;
        }

    case 3:
    {
        printf("\n");
        printf(" Insertion The End\n");
        printf("--------------------\n");
        int data;
        printf("Enter the data: \n");
        scanf("%d", &data);
        printf("-------------------------\n");
        head = insertionAtEnd(head, data);
        linkedListTraversal(head);
        printf("-------------------------\n");
        printf("\n");
        break;
    }

    case 4:
    {
        printf("\n");
        printf(" Insertion After Node\n");
        printf("-----------------------\n");
        int data;
        printf("Enter the data: \n");
        scanf("%d", &data);
        printf("-------------------------\n");
        head = insertionAfteNode(head, second, data);
        linkedListTraversal(head);
        printf("-------------------------\n");
        printf("\n");
        break;
    }
    
    default:
        printf("Something Went Wrong\n");
        break;
    }
    return 0;
}