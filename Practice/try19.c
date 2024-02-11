#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void linkedlistTraveral(struct Node* ptr)
{
    while(ptr!=NULL){
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueueF(int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    if(q==NULL){
        printf("The Queue is Full!\n");
    } else{
        q->data = value;
        q->next = f;
        f = q;
        if(r==NULL){
            r = q;
        }
    }
}

void enqueueR(int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    if(q==NULL){
        printf("The Queue is Full!\n");
    } else{
        q->data = value;
        q->next = NULL;
        if(f==NULL){
            f = r = q;
        } else{
            r->next = q;
            q = r;
        }
    }
}

int dequeueF()
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

int dequeueR()
{
    int value = -1;
    if(f==NULL){
        printf("The Queue is Empty!\n");
    } else{
        struct Node* q = f;
        struct Node* p = NULL;
        while(q->next!=NULL){
            p = q;
            p = p->next;
        }
        if(p!=NULL){
            p->next = NULL;
            r = p;
        } else{
            value = q->data;
            free(q);
        }
    }
    return value;
}

void Opeartion()
{
    printf("\n");
    printf("1: Linked List Travearl\n");
    printf("2: enqueueF\n");
    printf("3: enqueueR\n");
    printf("4: dequeueF\n");
    printf("5: dequeueR\n");
    printf("\n"); 
}

int main(){
    int size, value, query;
    
    printf("Enter the size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Element %d", i+1);
        scanf("%d", &value);
        enqueueR(value);
    }
    printf("Queue has been created successfully!\n");

    while (1)
    {
        printf("\n");
        Opeartion();
        printf("\n");
        printf("Enter the Operation Number || 0 to Exit: ");
        scanf("%d", &query);
        
        switch(query){
            case 1:
            {
                printf("\n");
                printf(" Linked List Traversal\n");
                printf("------------------------\n");
                linkedlistTraveral(f);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" enqueueF\n");
                printf("-----------\n");
                printf("Enter the Value: ");
                scanf("%d", &value);
                enqueueF(value);
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" enqueueR\n");
                printf("------------\n");
                printf("Enter the value: ");
                scanf("%d", &value);
                enqueueR(value);
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" dequeueF\n");
                printf("------------\n");
                int dequeueFvalue = dequeueF();
                printf("Element %d\n", dequeueFvalue);
                printf("\n");
                break;
            }
            
            case 5:
            {
                printf("\n");
                printf(" dequeueR\n");
                printf("------------\n");
                int dequeueRvalue = dequeueF();
                printf("Element %d\n", dequeueRvalue);
                printf("\n");
                break;
            }
        }
    }
    
}