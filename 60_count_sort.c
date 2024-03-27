#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void makeArray(int *arr, int size){
    printf(" Make Array\n");
    printf("----------------\n");
    for(int i = 0; i<size; i++){
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    printf(" Displaying Array\n");
    printf("---------------------\n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

int maximum(int *arr, int size){
    int max = INT_MIN;
    for(int i = 0; i<size; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }

    return max;
}

void countSort(int *arr, int size){
    int i, j;

    // Find the Max element in Array
    int max = maximum(arr, size);

    // Make a counter array
    int *count = (int*)malloc((max+1)*sizeof(int));

    // Initilize the counter Array
    for(i = 0; i<max+1; i++){
        count[i] = 0;
    }

    // Incriment the Corresponding index in the counter array
    for(int i = 0; i<size; i++){
        count[arr[i]] = count[arr[i]] +1;
    }

    i = 0; // Pointer for the counter Array
    j = 0; // Pointer for the main Array
    
    // Copy to new array
    while(i<=max){
        if(count[i]>0){
            arr[j] = i;
            count[i]--;
            j++;
        } else{
            i++;
        }
    }
}

int main(){
    while(1){
        int size, query;

        printf("\n");
        printf("Enter the size: ");
        scanf("%d", &size);
        printf("\n");

        int arr[size];
        makeArray(arr, size);
        printf("\n");

        displayArray(arr, size);
        printf("\n");

        printf(" countSort\n");
        printf("-------------\n");
        printf("\n");
        countSort(arr, size);
        displayArray(arr, size);
        printf("\n");
    }
    
    return 0;
}