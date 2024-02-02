#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void Opeartion()
{
    printf("\n");
    printf("1: Linked List Traveral\n");
    printf("2: enqueue\n");
    printf("3: dequeue\n");
    printf("\n");
}

void linkedListTraversal(struct Node* ptr)
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
        printf("The Queue is Full\n");
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
    int size, query, value;
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &value);
        enqueue(value);
    }
    printf("\n");
    linkedListTraversal(f);
    printf("\n");
    printf("Queue ha been created successfully!\n");

    while (1)
    {
        printf("\n");
        Opeartion();
        printf("\n");
        printf("Enter the Operation || 0 to Exit: ");
        scanf("%d", &query);

        if(query==0){
            printf("\n");
            printf("Exiting the Loop!\n");
            printf("\n");
            return -1;
            break;
        }

        switch (1)
        {
            case 1:
            {
                printf("\n");
                printf(" Linked List Traveral\n");
                printf("--------------------------\n");
                linkedListTraversal(f);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" enqueue\n");
                printf("-------------\n");
                printf("Enter the size: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++)
                {
                    printf("Element %d: ", i+1);
                    scanf("%d", &value);
                    enqueue(value);
                }
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" dequeue\n");
                printf("-----------\n");
                int dequeueval = dequeue();
                printf("Element %d", dequeueval);
                printf("\n");
                break;
            }
        
        default:
            printf("Something Went Wron!\n");
            break;
        }
    }
    
    return 0;
}