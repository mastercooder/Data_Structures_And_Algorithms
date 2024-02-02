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
            r = f;
        }
    }
}

void enqueueR(int value)
{
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    if(q==NULL){
        printf("The Stack is Full\n");
    } else{
        q->data = value;
        q->next = NULL;
        if(f==NULL){
            f = r = q;
        } else{
            r->next = q;
            r=q;
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
    if(f!=NULL){
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
    printf("1: Linked List Traveral\n");
    printf("2: enqueueF\n");
    printf("3: enqueueR\n");
    printf("\n");
}
int main(){
    int size, value, query;
    printf("Enter the size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &value);
        enqueueR(value);
    }
    printf("Queue has been created successfully!\n");

    while (1)
    {
        printf("\n");
    }
    return 0;
}