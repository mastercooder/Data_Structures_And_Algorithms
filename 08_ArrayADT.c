# include<stdio.h>
# include<stdlib.h>
# include<string.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int));
}

void setValue(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {   
        printf("Enter the value: \n");
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("The %d value is: %d\n", i, (a->ptr)[i]);
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("\n");
    printf("We are running setvalue now:-\n");
    setValue(&marks);
    printf("\n");
    printf("\n");
    printf("We are running setvalue now:-\n");
    show(&marks);
    printf("\n");
    printf("\n");

    return 0;
}

