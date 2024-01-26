#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

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

int main(){
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    makeStack(size);

    return 0;
}