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
    printf("3: pop\n");
    printf("4: peek\n");
    printf("\n");
}

int isFull(struct Stack* ptr)
{
    if(ptr->top == ptr->size-1){
        return 1;
    } else{
        return 0;
    }
}

int isEmpty(struct Stack* ptr)
{
    if(ptr->top == -1){
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

int pop(struct Stack* ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
    } else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main(){
    int size, query;
    
    printf("\n");
    printf("Enter the size of Stack: ");
    scanf("%d", &size);
    printf("\n");

    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Stack has been creeated Successfully\n");

    printf("\n");
    Opearation();
    printf("\n");

    while (1)
    {
        printf("\n");
        printf("Enter the Opeation || 0 to exit: ");
        scanf("%d", &query);
        printf("\n");

        if(query==0){
            printf("Exiting The loop\n");
            return -1;
        }

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Stack Status\n");
                printf("---------------\n");
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
                printf(" Push Operation \n");
                printf("----------------\n");
                printf("\n");
                if(isFull(s)){
                    printf("The stack is Full\n");
                } else{
                    printf("Enter the value\n");
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
                printf(" Pop Operation\n");
                printf("----------------\n");
                printf("\n");
                if(isEmpty(s)){
                    printf("The Stack is Empty\n");
                } else{
                    printf("Printing Stack\n");
                    for (int i = 0; i < size; i++)
                    {
                        int valueprint = pop(s);
                        printf("%d\n", valueprint);
                    }
                }
                printf("\n");
                break;
            }

            case 4:
            {
                printf("\n");
                printf(" Peek Opeartion\n");
                printf("------------------\n");
                printf("\n");
                if(isEmpty(s)){
                    printf("The Stack is Empty\n");
                } else{
                    continue;
                }
                printf("\n");
                break;
            }
        
        default:
            printf("Something went Wrong\n");
            break;
        }
    }
}