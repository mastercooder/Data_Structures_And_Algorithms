#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue* q){
    if(q->r==q->size-1){
        return 1;
    } else{
        return 0;
    }
}

int isEmpty(struct queue* q){
    if(q->r==q->f){
        return 1;
    } else{
        return 0;
    }
}

void enqueue(struct queue* q, int data){
    if(isFull(q)){
        printf("Queue Overflow!\n");
    } else{
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct queue* q){
    int data = -1;
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
    } else{
        q->f++;
        data = q->arr[q->f];
    }
    return data;
}

int main(){
    struct queue q;
    q.size = 400;
    q.r = q.f = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // BFS Implementation
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // enqueu i for exploration 

    while(!isEmpty(&q)){
        int Node = dequeue(&q);
        for(int j = 0; j<7; j++){
            if(a[Node][j]==1 && visited[j]==0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}