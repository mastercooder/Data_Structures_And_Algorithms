#include<stdio.h>
#include<stdlib.h>

// To Reduce pointer use
struct Node* top = NULL;

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
}

void Operation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: Operation\n");
    printf("3: Linked List Traveral\n");
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
        printf("Stack Overflow\n");
    } else{
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = value;
        p->next = top;
        top = p;
    }
}

int pop(struct Node* ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
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

    printf("Enter the size of stack: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Elment %d: ", i+1);
        scanf("%d", &value);
        push(top, value);
    }

    printf("\n");
    linkedListTraversal(top);
    printf("\n");

    Operation();

    while (1)
    {
        printf("Enter the Opeation || 0 to Exit: ");
        scanf("%d", &query);

        if(query==0){
            printf("\n");
            printf("Exiting The loop\n");
            printf("\n");
            return -1;
        }
    
        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Status\n");
                printf("----------\n");
                if(isEmpty(top)){
                    printf("The Stack is Empty\n");
                } else{
                    printf("The Stack is not Empty\n");
                }
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" Opeation\n");
                printf("-------------\n");
                Operation();
                printf("\n");
                break;
            }
        
            case 3:
            {
                printf("\n");
                printf(" Linked List Traversal\n");
                printf("--------------------------\n");
                linkedListTraversal(top);
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" Push Operation\n");
                printf("-------------------\n");
                int size;
                printf("How many element you to enter: ");
                scanf("%d", &size);
                printf("\n");
                for (int i = 0; i < size; i++)
                {
                    int value;
                    printf("Element %d: a", i+1);
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
                printf("------------------\n");
                int value = pop(top);
                printf("Element %d", value);
                printf("\n");
                break;
            }

        default:
            printf("Something Went Wrong\n");
            break;
        }
    }
    return 0;
}
