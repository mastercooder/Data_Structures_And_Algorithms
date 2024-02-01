#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int value)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if (q == NULL)
    {
        printf("Memory Allocation Failed! The Queue is Full!\n");
    }
    else
    {
        q->data = value;
        q->next = NULL;
        if (f == NULL)
        {
            f = r = q;
        }
        else
        {
            r->next = q;
            r = q;
        }
    }
}

int dequeue()
{
    int value = -1;
    if (f == NULL)
    {
        printf("The Queue is Empty!\n");
    }
    else
    {
        struct Node *temp = f;
        f = f->next;
        value = temp->data;
        free(temp);
    }
    return value;
}

int main()
{
    int size, query;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }
    printf("\n");
    linkedListTraversal(f);
    printf("Queue has been created successfully!!!\n");

    while (1)
    {
        printf("Enter the Operation (1: enqueue, 2: dequeue, 0: Exit): ");
        scanf("%d", &query);

        switch (query)
        {
        case 1:
        {
            printf("\n");
            printf(" enqueue\n");
            printf("-------------\n");
            int size, value;
            printf("How many elements you want to enter in the Queue: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Enter the value: ");
                scanf("%d", &value);
                enqueue(value);
            }
            linkedListTraversal(f);
            printf("\n");
            break;
        }

        case 2:
        {
            printf("\n");
            printf(" dequeue\n");
            printf("-------------\n");
            int dequeuedValue = dequeue();
            if (dequeuedValue != -1)
            {
                printf("Dequeued Element: %d\n", dequeuedValue);
            }
            linkedListTraversal(f);
            printf("\n");
            break;
        }

        case 0:
            printf("Exiting The Loop!\n");
            return 0;

        default:
            printf("Invalid Operation! Try Again.\n");
            break;
        }
    }

    return 0;
}
