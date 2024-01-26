#include <stdio.h>
#include <stdlib.h>

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
    printf("3: pop\n");
    printf("\n");
}
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main()
{
    int size, query;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    p->size = size;
    p->top = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));

    printf("\n");
    printf(" Your Stack is been created Successfully\n");
    printf("------------------------------------------\n");
    printf("\n");
    Opearation();

    while (1)
    {
        printf("\n");
        printf("Enter the Opearation You want to perform || 0 to Exit: ");
        scanf("%d", &query);
        printf("\n");

        if (query==0)
        {
            printf("Exiting The loop\n");
            return -1;
        }

        switch (query)
        {
        case 1:
        {
            printf("\n");
            printf(" Status\n");
            printf("---------\n");
            if(isEmpty(p)){
                printf("The Stack is Empty\n");
            } else{
                printf("The Stack is not Empty\n");
            }
        }

        case 2:
        {
            printf("\n");
            printf(" Push Opeartion\n");
            printf("-----------------\n");
            int value;
            if(isFull(p)){
                printf("The Stack is full!!!\n");
            } else{
                printf("\n");
                printf(" Enter the value \n");
                printf("------------------\n");
                for (int i = 0; i < size; i++)
                {
                    printf("Value %d: ", i+1);
                    int value;
                    scanf("%d", &value);
                    push(p, value);
                }
            }
            break;
        }

        case 3:
        {
            printf("\n");
            printf(" Pop Opeation\n");
            printf("----------------\n");
            printf("\n");
            if(isEmpty(p)){
                printf("\n");
                printf("The Stack is empty\n");
                printf("\n");
            } else{
                printf("Printing Value from stack \n");
                for (int i = 0; i < size; i++)
                {
                    int vlaueprint = pop(p);
                    printf("%d\t", vlaueprint);
                }
            }
            printf("\n");
            break;
        }

        default:
            printf("Something went wrong\n");
            break;
        }
    }
}