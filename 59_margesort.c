#include<stdio.h>

void makeArray(int arr[], int size){
    printf(" Start entering your array: \n");
    printf("----------------------------\n");
    for (int i = 0; i < size; i++){
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size){
    printf(" Printing Array\n");
    printf("-------------------\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void marge(int *A, int low, int mid, int high){
    int i, j, k, B[100];
    i = low; // Point the First Element of Array A
    j = mid+1; // Point the Mid Element of Array A
    k = low; // Point the First Element of Array B

    // Copy element from Array A to B by sorting
    while(i <= mid && j <= high){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++;
            k++;
        } else{
            B[k] = A[j];
            j++;
            k++;
        }
    }

    // Coping the remaining element
    while(i<=mid){
        B[k] = A[i];
        i++;
        k++;
    }

    while(j<=high){
        B[k] = A[j];
        j++;
        k++;
    }
    
    // Copy Array B to Array A
    for(int i = low; i<=high; i++){
        A[i] = B[i];
    }
}

void margeSort(int *A, int low, int high){
    int mid;
    if(low<high){
        mid = (low + high) / 2;
        margeSort(A, low, mid);
        margeSort(A, mid+1, high);
        marge(A, low, mid, high);
    }
}

int main(){
    int size, query;

    printf("\n");
    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("\n");
    int arr[size];
    makeArray(arr, size);
    printf("\n");

    printf("\n");
    displayArray(arr, size);
    printf("\n");

    printf("\n");
    printf("After Marge Sort\n");
    margeSort(arr, 0, size-1);
    printf("\n");
    displayArray(arr, size);
    printf("\n");
    return 0;
}