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
    // -1   0    1   2   3   4   5
    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

    // Fast forwarding and 4th and 5th pass will give:
    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
    //      07, 09, 12, 23, 54, 65| --> After the 5th pass
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
