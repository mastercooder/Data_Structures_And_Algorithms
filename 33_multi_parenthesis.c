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
    if(ptr->top==-1){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if(ptr->top==ptr->size-1){
        return 1;
    } else{
        return 0;
    }
}

void push(struct Stack *ptr, char    value)
{
    if(isFull(ptr)){
        printf("Stack Overflow\n");
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

int match(char a, char b)
{
    if (a == '(' && b == ')'){
        return 1;
    } else if (a == '{' && b == '}') {
        return 1;
    } else if (a == '[' && b == ']') {
        return 1;
    } else {
        return 0;
    }
}


int parenthisisMatch(char *exp, int size)
{
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(sp, exp[i]);
        } else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty(sp)){
                return 0;
            } else{
                popped_ch = pop(sp);
                if(!match(popped_ch, exp[i])){
                    return 0;
                }
            }
        }
    }
    
    if(isEmpty(sp)){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    int size;

    printf("Enter the size of your expression: ");
    scanf("%d", &size);

    while (1)
    {
        char query[size];
        printf("Enter the Expression: ");
        scanf("%s", query);

        if(parenthisisMatch(query, size)){
            printf("Expression Balanced\n");
        } else{
            printf("Expression Not Balanced\n");
        }
    }
       return 0;
}