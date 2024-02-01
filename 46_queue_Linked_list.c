#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void linkedListTraveral(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    if(q==NULL){
        printf("The Queue is Full!\n");
    } else{
        q->data = value;
        q->next = NULL;
        if(f==NULL){
            f=r=q;
        } else{
            r->next = q;
            r=q;
        }
    }
}

int dequeue()
{
    int value = -1;
    if(f==NULL){
        printf("The Queue is Empty!\n");
    } else{
        f = f->next;
        value = f->data;
        free(f);
    }
    return value;
}

int main(){
    int size, query;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i+1);
        scanf("%d", value);
        enqueue(value);
    }
    printf("\n");
    linkedListTraveral(f);
    printf("Queue has been created successfully!!!\n");
    
    while (1)
    {
        printf("Enter the Opeartion: ");
        scanf("%d", &query);

        switch (1)
        {
            case 1:
            {
                printf("\n");
                printf(" enqueue\n");
                printf("-------------\n");
                int size, value;
                printf("How much element you want to enter the Queue: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++)
                {
                    int value;
                    printf("Enter the value: ");
                    scanf("%d", &value);
                    enqueue(value);
                }
                linkedListTraveral(f);
                printf("\n");
                break;
            }
        
            case 2:
            {
                printf("\n");
                printf(" dequeue\n");
                printf("-------------\n");
                dequeue();
                linkedListTraveral(f);
                printf("\n");
                break;
            }

        default:
            printf("Something Went Wrong!\n");
            break;
        }
    }
    
}