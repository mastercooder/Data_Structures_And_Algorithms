#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    if(ptr->top == -1){
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

int stackTop(struct Stack *ptr){
    return ptr->arr[ptr->top];
}

void push(struct Stack *ptr, char value)
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

int precedence(char ch)
{
    if(ch=='*' || ch=='/'){
        return 2;
    } else if(ch=='+' || ch=='-'){
        return 1;
    } else{
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        return 1;
    } else{
        return 0;
    }
}

char *infixtoPostfix(char *infix, int size)
{
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *postFix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postFix[j] = infix[i];
            i++;
            j++;
        } else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            } else{
                postFix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)){
        postFix[j] = pop(sp);
        j++;
    }
    postFix = '\0';
    return postFix;
}

int main(){
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    char query[size];
    printf("Enter the Expression: ");
    scanf("%d", query);
    printf("\n");
    printf("The Infix is: %s\n", query);
    printf("The postFix is: %s", infixtoPostfix(query, size));
    
    
    return 0;
}