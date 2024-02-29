#include<stdio.h>

void makeArray(int *arr, int size){
    printf(" Make Array\n");
    printf("----------------\n");
    for(int i = 0; i<size; i++){
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    printf(" Dipaly Array\n");
    printf("-------------------\n");
    for(int i = 0; i<size; i++){
        printf("%d: %d\t", i+1, arr[i]);
    }
}

int partion(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(arr[i]<=pivot){
            i++; // Keep running until get an element grater than pivot;
        }
        while(arr[j]>pivot){
            j--; // Keep running until get an element less than pivot;
        }

        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i < j);

    // Swap arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quichSort(int *arr, int low, int high){
    int partitionIndex; // Set pivot

    if(low < high){
        partitionIndex = partion(arr, low, high);
        quichSort(arr, low, partitionIndex-1); // Sort the left Array
        quichSort(arr, partitionIndex+1, high); // Sort the right Array 
    }
}

int main(){
    printf("\n");
    while(1){
        printf("\n");
        int size;
        printf("Enter the size of the Array: ");
        scanf("%d", &size);

        int arr[size];
        printf("\n");
        makeArray(arr, size);
        printf("\n");

        printf("\n");
        displayArray(arr, size);
        printf("\n");

        printf("\n");
        printf(" quickSort\n");
        printf("--------------\n");
        quichSort(arr, 0, size-1);
        printf("\n");
        displayArray(arr, size);
        printf("\n");
    }
    return 0;
}