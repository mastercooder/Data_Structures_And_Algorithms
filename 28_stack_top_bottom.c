#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void Operation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: push\n");
    printf("3: stackTop\n");
    printf("4: Stack Bottom\n");
    printf("\n");
}

int isEmpty(struct Stack* ptr)
{
    if(ptr->top == -1){
        return 1;
    }else{
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
        printf("Stack Overflow!\n");
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int stackTop(struct Stack* ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct Stack *ptr)
{
    return ptr->arr[0];
}

int main(){
    int size, query;

    printf("\n");
    printf("Enter the size of Stack: ");
    scanf("%d", &size);
    printf("\n");

    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(s->size* sizeof(int));
    printf("Stack has been created successfully\n");
    printf("\n");
    Operation();
    printf("\n");

    while (1)
    {
        printf("\n");
        printf("Enter the Opeation you want to perfrom || 0 to Exit: ");
        scanf("%d", &query);
        printf("\n");

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Status\n");
                printf("----------\n");
                printf("\n");
                if(isEmpty(s)){
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
                printf(" Push Opeation\n");
                printf("------------------\n");
                if(isFull(s)){
                    printf("Stack is currently Full\n");
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
                printf(" Stack Top Operation\n");
                printf("-----------------------\n");
                printf("\n");
                if(isEmpty(s)){
                    printf("The Stack is Empty\n");
                } else{
                    int printstacktop = stackTop(s);
                    printf("Element %d\n", printstacktop);
                }
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" Stack Bottom Operation\n");
                printf("-------------------------\n");
                if(isEmpty(s)){
                    printf("The Stack is Empty\n");
                }else{
                    int printstackbottom = stackBottom(s);
                    printf("Element %d", printstackbottom);
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
