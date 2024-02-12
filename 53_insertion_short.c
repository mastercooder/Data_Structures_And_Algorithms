#include<stdio.h>

void makeArray(int *arr, int size){
    printf(" Enter Element In Array\n");
    printf("------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionShort(int *arr, int size){
    int key, j;
    for (int i = 1; i <= size-1; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(){
    while(1){
        printf("\n");
        int size;
        printf("Enter the size: ");
        scanf("%d", &size);

        int arr[size];

        printf("\n");
        makeArray(arr, size);
        printf("\n");

        printf(" Printing Array\n");
        printf("------------------\n");
        displayArray(arr, size);
        printf("\n");

        printf(" After Shorting\n");
        insertionShort(arr, size);
        displayArray(arr, size);
        printf("\n");
    }

    return 0;
}
