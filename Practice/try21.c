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
    printf(" Displaying Array\n");
    printf("---------------------\n");
    for(int i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}

void bubbleshortAdvance(int *arr, int size){
    int isSorted, temp;
    
    for(int i = 0; i<size-1; i++){
        printf("Number of passes %d\n", i+1);
        isSorted = 1;
    
        for(int j = 0; j < size-1-i; j++){
            if (arr[j]>arr[j+1]){
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

void insertionSort(int *arr, int size){
    int key, j;
    for(int i = 0; i <= size-1; i++){
        key = arr[i];
        j = i-1;
        while(j >=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int *arr, int size){
    int indexOfMin, temp;
    for(int i = 0; i < size-1; i++){
        indexOfMin = i;
        for(int j = i+1; j < size; j++){
            if(arr[j]<arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

void Opeartion(){
    printf("\n");
    printf("1: bubbleSortAdvance\n");
    printf("2: insertionSort\n");
    printf("3: selectionSort\n");
    printf("\n");
}

int main(){
    printf("\n");
    while (1){
        int size, query;
        printf("Enter the size: ");
        scanf("%d", &size);
        
        printf("\n");
        int arr[size];
        makeArray(arr, size);
        printf("\n");

        displayArray(arr, size);
        printf("\n");

        Opeartion();
        printf("\n");
        printf("Enter the Opeartion Number || 0 to eixt: ");
        scanf("%d", &query);
        printf("\n");

        switch(query){
            case 1:
            {
                printf("\n");
                printf(" bubbleshortAdvance\n");
                printf("--------------------\n");
                bubbleshortAdvance(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 2:
            {
                printf("\n");
                printf(" insertionSort\n");
                printf("------------------\n");
                insertionSort(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 3:
            {
                printf("\n");
                printf(" selectionSort\n");
                printf("------------------\n");
                selectionSort(arr, size);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }
        }
    }

    printf("\n");
    return 0;
}