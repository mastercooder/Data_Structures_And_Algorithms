#include<stdio.h>

void makeArray(int *arr, int size){
    printf(" Enter Array\n");
    printf("----------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    printf(" Printing Array\n");
    printf("--------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void insertionShot(int *arr, int size){
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}


void bubbleShortAdaptive(int *arr, int size){
    int temp, isSorted;
    for (int i = 0; i < size-1; i++)
    {
        printf("Number of Pass Done %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(isSorted){
            return;
        }
    }
    
}

int main(){
    int size, query;
    printf("Enter the Size: ");
    scanf("%d", &size);

    int arr[size];
    printf("\n");
    makeArray(arr, size);
    printf("\n");

    displayArray(arr, size);
    printf("\n");

    while(1){

        printf("\n");
        printf("Enter the Opeartion Number: ");
        scanf("%d", &query);
        printf("\n");

        if(query==0){
            printf("\n");
            printf("Exiting the Loop!\n");
            printf("\n");
            return -1;
        }

        switch(query){
            case 1:
            {
                printf("\n");
                printf(" insertionShort\n");
                printf("------------------\n");
                insertionShot(arr, size);
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" bubbleSort\n");
                printf("--------------\n");
                bubbleShortAdaptive(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }
        }
    }
}