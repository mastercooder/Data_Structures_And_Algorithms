#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void Opearation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: push\n");
    printf("3: peek\n");
    printf("\n");
}

int isEmpty(struct Stack* ptr)
{
    if(ptr->top == -1){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct Stack* ptr)
{
    if(ptr->top == ptr->size-1){
        return 1;
    } else{
        return 0;
    }
}

void push(struct Stack* ptr, int value)
{
    if(isFull(ptr)){
        printf("The Stack is full\n");
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int peek (struct Stack* ptr, int index)
{
    int arrayint = ptr->top - index + 1;
    if(arrayint<0){
        printf("Enter a valid Number for Stack\n");
        return -1;
    } else{
        return ptr->arr[arrayint];
    }
}

int main(){
    int size, query;
    printf("Enter the size: ");
    scanf("%d", &size);

    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Stack has been created Successfully\n");
    printf("\n");

    Opearation();
    printf("\n");
    while (1)
    {
        printf("Enter the Opeation you want to perfrom || 0 to Exit: ");
        scanf("%d", &query);
        printf("\n");

        if (query==0)
        {
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
                if(isEmpty(s)){
                    printf("The Stack is Empty\n");
                } else{
                    printf("The stack is not empty\n");
                }
                printf("\n");
                break;
            }
            
            case 2:
            {
                printf("\n");
                printf(" Push Operation\n");
                printf("------------------\n");
                if(isFull(s)){
                    printf("The stack is full\n");
                } else{
                    for (int i = 0; i < size; i++)
                    {
                        int value;
                        printf("Element %d: ", i+1);
                        scanf("%d", &value);
                        push(s, value);
                    }
                }
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" Peek Opearation\n");
                printf("-------------------\n");
                if(isEmpty(s)){
                    printf("The stack is empty\n");
                } else{
                    int index;
                    printf("Enter the index: ");
                    scanf("%d", &index);
                    int printpeek = peek(s, index);
                    printf("Element %d\n", printpeek);
                }
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