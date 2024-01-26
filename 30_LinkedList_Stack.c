#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void linkedListTraveral(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void operation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: Linked List Traversal\n");
    printf("3: Operation\n");
    printf("4: push\n");
    printf("5: pop\n");
    printf("\n");
}

int isEmpty(struct Node* ptr)
{
    if(ptr==NULL){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct Node* ptr)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    } else{
        return 0;
    }
}

struct Node* push(struct Node* ptr, int value)
{
    if(isFull(ptr)){
        printf("Stack Overflow!\n");
    } else{
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = value;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(struct Node* ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
    } else{
        struct Node* p = top;
        top = top->next;
        int value = p->data;
        free(p);
        return value;
    }
}

int main(){
    int size, query;
    printf("Enter the size of Stack: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i+1);
        scanf("%d", &value);
        push(top, value);
    }
    
    printf("\n");
    operation();
    printf("\n");

    switch (query)
    {
        case 1:
        {
            printf("\n");
            printf(" Status\n");
            printf("------------\n");
            if(isEmpty(top)){
                printf("The Stack is Empty\n");
            } else{
                printf("The Stack is Not Empty\n");
            }
            printf("\n");
            break;
        }

        case 2:
        {
            printf("\n");
            printf(" Linked List Traversal\n");
            printf("--------------------------\n");
            linkedListTraveral(top);
            printf("\n");
            break;
        }

        case 3:
        {
            printf("\n");
            printf(" Opeation\n");
            printf("------------\n");
            operation();
            printf("\n");
            break;
        }

        case 4:
        {
            printf("\n");
            printf(" Push Opeation\n");
            printf("-----------------\n");
            int size;
            printf("How many element you wan to enter: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                int value;
                printf("Element %d: ", i+1);
                scanf("%d", &value);
                push(top, value);
            }
            printf("\n");
            break;
        }

        case 5:
        {
            printf("\n");
            printf(" Pop Operation\n");
            printf("-----------------\n");
            int value = pop(top);
            printf("The First Element is: %d", value);
            printf("\n");
            break;
        }

        case 6:
        {
            printf("\n");
            printf(" Insert At Index\n");
            printf("-------------------\n");
            int index, value;
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Enter Value: ");
            scanf("%d", &value);
            top = insertAtIndex(top, index, value);
            printf("\n");
            break;
        }
        
    default:
        printf("Something Went Wrong\n");
        break;
    }

}