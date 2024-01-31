#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void operation()
{
    printf("\n");
    printf("1: Status\n");
    printf("2: enqueue\n");
    printf("3: dequeue\n");
    printf("\n");
}

int isEmpty(struct circularQueue *q)
{
    if(q->r==q->f){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct circularQueue *q)
{
    if((q->r + 1) % q->size == q->f){
        return 1;
    } else{
        return 0;
    }
}

void enqueue(struct circularQueue *q, int value)
{
    if(isFull(q)){
        printf("Queue is Currently Full!\n");
    } else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = value;
    }
}

int dequeue(struct circularQueue *q)
{
    int value = -1;
    if(isEmpty(q)){
        printf("The Queue is Currently Empty!\n");
    } else{
        q->f = (q->f +1)%q->size;
        value = q->arr[q->f];
    }
    return value;
}

int main(){
    int size, query;   
    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    struct circularQueue q;
    q.size = size; 
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Element %d: ", i+1);
        scanf("%d", &value);
        enqueue(&q, value);
    }
    
    printf("Queue has been created Successfully!\n");
    printf("\n");
    operation();
    
    while (1)
    {
        printf("Enter the Operation Number || 0 to Exit: ");
        scanf("%d", &query);

        if(query==0){
            printf("\n");
            printf("Exiting The Loop!\n");
            printf("\n");
            return -1;
        }

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" Status\n");
                printf("-----------\n");
                if(isEmpty(&q)){
                    printf("The Queue is Emptry!\n");
                } else{
                    printf("The Queue is Not Emptry\n");
                }
                printf("\n");
                break;
            }
        
            case 2:{
                printf("\n");
                printf(" emqueue\n");
                printf("------------\n");
                int size;
                printf("Enter how many element you want to enter: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++)
                {
                    int value;
                    printf("Element %d: ", i+1);
                    scanf("%d", &value);
                    enqueue(&q, value);
                }
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" dequeue\n");
                printf("------------\n");
                printf("Element %d", dequeue(&q));
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