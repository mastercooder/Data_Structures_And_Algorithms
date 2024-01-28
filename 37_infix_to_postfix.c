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

char *infixtoPostfix(char *infix, int size)
{
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *postFix = (char*)malloc((strlen(infix)+1))sizeof(char);

}

int main(){
    char query[50] = "2-4+5";
    return 0;
}