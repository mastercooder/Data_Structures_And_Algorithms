#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

void Operation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: parenthisisMatch\n");
    printf("\n");
}

int isEmpty(struct Stack *ptr)
{
    if(ptr->top==-1){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if(ptr->top == ptr->size-1){
        return 1;
    } else{
        return 0;
    }
}

void push(struct Stack *ptr, int value)
{
    if(isFull(ptr)){
        printf("Stack Overflow!\n");
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct Stack *ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
    } else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int parenthisisMatch(char *exp, int size)
{
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        } else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        } 
    }

    if(isEmpty(sp)){
        return 1;
    } else{
        return 0;
    }

}

int main(){
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    int query, size = 100;

    while (1)
    {
        printf("Enter The Opeartion Number: ");
        scanf("%d", &query);

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Status\n");
                printf("-----------\n");
                if(isEmpty(sp)){
                    printf("The Stack is Empty\n");
                }else{
                    printf("The Stack is not Empty\n");
                }
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" parenthisisMatch\n");
                printf("--------------------\n");
                char user[size];
                printf("\n");
                printf("Enter the expression: ");
                scanf("%s", user);

                printf("\n");
                if(parenthisisMatch(user, size)){
                    printf("Parenthesis Balanced\n");
                } else{
                    printf("Parenthesis Not Balanced\n");
                }
                printf("\n");
                break;  
            }
        
        default:
            printf("Something Went Wrong!\n");
            break;
        }
    }

    return 0;
}