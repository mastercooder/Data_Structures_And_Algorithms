#include<stdio.h>

// ----------------------------------------------ArrayOperation-------------------------------------------
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


// ----------------------------------------------bubbleSort------------------------------------------- 
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


// ----------------------------------------------insertionSort-------------------------------------------
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


// ----------------------------------------------selectionSort-------------------------------------------
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


// ------------------------------------------------quickSort-----------------------------------------------
int partion(int *arr, int low, int high){
    int pivod = low;
    int i = low+1;
    int j = high;
    int temp;

    do{
        while(arr[i]<=pivod){
            i++;
        }
        while(arr[j]>pivod){
            j--;
        }

        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, int low, int high){
    int partitionIndex;

    if(low < high){
        partitionIndex = partion(arr, low, high);
        quickSort(arr, low, partitionIndex-1); // Sort the left Array
        quickSort(arr, partitionIndex+1, high); // Sort the right Array 
    }
}


// ----------------------------------------------margeSort---------------------------------------------------
void marge(int *A, int low, int mid, int high){
    int i, j, k, B[100];
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        } else{
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        B[k] = A[i];
        i++;
        k++;
    }

    while(j <= high){
        B[k] = A[j];
        j++;
        k++;
    }

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


// ---------------------------------------------------------------------------------------------------------------
void Opeartion(){
    printf("\n");
    printf("1: bubbleSortAdvance\n");
    printf("2: insertionSort\n");
    printf("3: selectionSort\n");
    printf("4: quickSort\n");
    printf("5: margeSort\n");
    printf("\n");
}

int main(){
    while (1){
        int size, query;
        printf("\n");
        printf("\n");
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

            case 4:
            {
                printf("\n");
                printf(" quickSort\n");
                printf("------------------\n");
                quickSort(arr, 0, size-1);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 5:
            {
                printf("\n");
                printf(" margeSort\n");
                printf("---------------\n");
                margeSort(arr, 0, size-1);
                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            default:
                printf("Something Went Wrong!\n");
        }

    }

    printf("\n");
    return 0;
}