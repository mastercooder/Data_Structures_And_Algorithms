#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
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

// fuction to Insert Array
void insertArray(int *arr, int size)
{
    printf("Enter the value of array here: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}
// function to Display Array
void displayArray(int *arr, int size)
{
    printf("Printing Array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    printf("\n");

    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // puching element manualy
    printf("\n");
    insertArray(s->arr, size);

    // Displaying Array
    printf("\n");
    displayArray(s->arr, size);

    // checking if the array is empty or not
    printf("\n");
    if (isEmpty(s))
    {
        printf("The Array is empty\n");
    }
    else
    {
        printf("The Array is not Empty\n");
    }
}
