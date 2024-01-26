#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Opeation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: Linked List Traversal\n");
    printf("3: push\n");
    printf("4: peek\n");
    printf("5: stackTop\n");
    printf("6: stackBottom\n");
    printf("\n");
}
void linkedListTraveral(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
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

int isEmpty(struct Node* ptr)
{
    if(ptr==NULL){
        return 1;
    } else{
        return 0;
    }
}

struct Node* push(struct Node* top, int value)
{
    if(isFull(top)){
        printf("Stack is Full Can't Add more item\n");
    } else{
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = value;
        p->next = top;
        top = p;
        return top;
    }
}

void makeStack(int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i+1);
        scanf("%d", &value);
        push(top, value);
    }
    printf("\n");
}

void peek(struct Node* ptr, int index)
{
    if(isEmpty(ptr)){
        printf("Stack is currently Empty\n");
    } else{
        struct Node* p = top;

        for (int i = 0; (i<index-1 && p!=NULL); i++)
        {
            p = p->next;
        }
        
        if(p!=NULL){
            printf("Element %d\n", p->data);
        } else{ 
            printf("Enter a valid index\n");
        }
    }
}

void stackTop(struct Node * ptr)
{
    if(isEmpty(ptr)){
        printf("Stack is Currently Emtpy\n");
    } else{
        printf("Element %d\n", top->data);
    }
}

void stackBottom(struct Node* ptr)
{
    if(isEmpty(ptr)){
        printf("Stack is Curretnly Emtpy\n");
    } else{
        struct Node* p = top;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        int value = p->data;
        free(p);
        printf("Element %d\n", value);
    }
}

int main(){
    int size, query;
    printf("Enter the size: ");
    scanf("%d", &size);

    makeStack(size);

    printf("Stack has been created Successfully\n");
    while (1)
    {
        Opeation();
        printf("Enter the Opeation Number: ");
        scanf("%d", &query);

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Status\n");
                printf("-----------\n");
                if(isEmpty(top)){
                    printf("Stack is currently Empty\n");
                } else{
                    printf("Stack is not Empty\n");
                }
                printf("\n");
                break;
            }
            
            case 2:
            {
                printf("\n");
                printf(" Linked List Traveral\n");
                printf("-------------------------\n");
                linkedListTraveral(top);
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" push Operation\n");
                printf("-------------------\n");
                int size;
                printf("Enter how much element you want to enter: ");
                scanf("%d", &size);
                makeStack(size);
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" peek Opeartion\n");
                printf("------------------\n");
                int index;
                printf("Enter the index: ");
                scanf("%d", &index);
                peek(top, index);
                printf("\n");
                break;
            }

            case 5:
            {
                printf("\n");
                printf(" stackTop Opeartion\n");
                printf("----------------------\n");
                stackBottom(top);
                printf("\n");
                break;
            }   

            case 6:
            {
                printf("\n");
                printf(" stackBottom Operation\n");
                printf("------------------------\n");
                stackBottom(top);
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