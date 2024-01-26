#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
} 

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;

    // Keep Searching until low<=high
    while (low<=high){
        mid = (low + high) / 2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }

    return -1;
}
int main(){
    int query;
    printf("Enter 1 for Leaner Search and 2 for Binary Search: ");
    scanf("%d", &query);

    switch (query){
        case 1:{
            int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 456, 464, 546, 646};
            int size = sizeof(arr) / sizeof(int);
            int element = 456;
            int searchIndex = linearSearch(arr, size, element);
            printf("The element %d was found at element %d", element, searchIndex);
        } 

        case 2:{
            int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 456, 464, 546, 646};
            int size = sizeof(arr) / sizeof(int);
            int element = 456;
            int serachIndex = binarySearch(arr, size, element);
            printf("\n");
            printf("The element %d was found at element %d \n", element, serachIndex);
        } 

        default:
            printf("Something went wrong!");
            break;
    }

    return 0;
}