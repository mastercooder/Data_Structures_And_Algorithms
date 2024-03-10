#include<stdio.h>

void makeArray(int *arr, int size){
    printf(" Insert In Array\n");
    printf("-------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    printf(" Diplay Array\n");
    printf("----------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int *arr, int size){
    printf("Selection Sort in Precess....\n");
    int indexOfMin, temp;
    for (int i = 0; i < size-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j]<arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp; 
    }
}

int main(){

    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    printf("\n");
    int arr[size];
    makeArray(arr, size);
    printf("\n");

    printf("\n");
    displayArray(arr, size);
    printf("\n");

    printf("\n"); 
    selectionSort(arr, size);
    printf("\n");
    displayArray(arr, size);
    printf("\n"); 
    return 0;
}