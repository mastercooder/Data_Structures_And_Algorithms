#include<stdio.h>

void makeArray(int *arr, int size){
    printf("  Insert Array\n");
    printf("-----------------\n");
    for (int i = 0; i < size; i++)
    {
        scanf(" %d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    printf(" Printing Array!\n");
    printf("-------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int *arr, int size){
    int temp;

    for (int i = 0; i < size-1; i++)
    {
        printf("Number of Pass %d\n", i+1);
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleShotAdaptive(int *arr, int size){
    int temp, isSorted;

    for (int i = 0; i < size-1; i++)
    {
        printf("Number of Pass %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

void opeartion(){
    printf("\n");
    printf("1: bubbleshort\n");
    printf("2: bubblesortAdaptive\n");
    printf("3: displayArray\n");
    printf("\n");
}

int main(){
    int size, query;

    printf("Enter the size of The Array: ");
    scanf("%d", &size);

    int arr[size];
    makeArray(arr, size);
    
    printf("Array has been Created!!!\n");

    while(1){
        printf("\n");
        opeartion();
        printf("\n");

        printf("Enter the number of opeartion: ");
        scanf("%d", &query);
        printf("\n");

        if (query==0){
            printf("\n");
            printf("Exiting The Loop!\n");
            return -1;
            printf("\n");
        }

        switch (query)
        {
            case 1:
            {
                printf("\n");
                printf(" bubbleSort\n");
                printf("----------------\n");
                bubbleSort(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" bubbleShotAdaptive\n");
                printf("-----------------------\n");
                bubbleShotAdaptive(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }
        
        default:
            printf("Something Went Wrong!!!\n");
            break;
        }
    }
}