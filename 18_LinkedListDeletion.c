#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while (ptr!=NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Delete From First
struct Node* deleteFromFirst(struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
};

// Case 2: Delete From Index
struct Node* deleteFromIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return(head);
};

struct Node* deletionFromEnd(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->next!=NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

struct Node* deletingNodeValue(struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data==value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
};



int main(){
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
    fifth->next = NULL;

    printf("\n");
    printf(" Linked List Traversal\n");
    printf("-----------------------\n");
    linkedListTraversal(head);
    printf("\n");

    printf(" Operations\n");
    printf("-------------\n");
    printf("\n");
    printf("1: Delete From First\n");
    printf("2: Delete from Index\n");
    printf("3: The last Node\n");
    printf("4: A Node with value\n");


    int query;
    while (1)
    {
        printf("\n");
        printf("Which Operation do you want to perfrom: \n");
        printf("Enter 0 to exit\n");
        scanf("%d", &query);
        printf("\n");

        if(query==0)
        {
            printf("\n");
            printf("Exiting The Loop\n");
            return -1;
            printf("\n");
        }


        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Deletion From First\n");
                printf("----------------------\n");
                head = deleteFromFirst(head);
                linkedListTraversal(head);
                break;
            }
            
            case 2:
            {
                printf("\n");
                printf(" Deletion From Index\n");
                printf("----------------------\n");
                int user;
                printf("Which Index you want to delete: ");
                scanf("%d", &user);
                head = deleteFromIndex(head, user);
                linkedListTraversal(head);
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" Deletion From End\n");
                printf("-----------------------\n");
                head = deletionFromEnd(head);
                linkedListTraversal(head);
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" Deleting From Node Value\n");
                printf("---------------------------\n");
                int user;
                printf("Which value you want to delete: ");
                scanf("%d", &user);
                printf("\n");
                head = deletingNodeValue(head, user);
                linkedListTraversal(head);
                break;   
            }

            default:
                printf("Something went wrong\n");
                break;
            }
    }
    return 0;
}

