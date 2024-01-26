#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void makeArray(int arr[], int size)
{
    printf("Enter the values of Array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size)
{
    printf(" Here is your array:\n");
    printf("--------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
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
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("\n");
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    struct Stack *s;
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Make Array
    printf("\n");
    makeArray(s->arr, size);
    printf("\n");

    // Display Array
    printf("\n");
    displayArray(s->arr, size);
    printf("\n");

    printf("\n");
    if (isEmpty(s))
    {
        printf("---------------------\n");
        printf(" The Array is Empty\n");
        printf("---------------------\n");
    }
    else
    {
        printf("-----------------------\n");
        printf(" The Array is Not Empty\n");
        printf("-----------------------\n");
    }
    printf("\n");
}