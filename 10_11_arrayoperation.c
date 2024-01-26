#include<stdio.h>

void makeArray(int arr[], int size){
    printf("Start entering your array: \n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size){
    // Traversal
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

int arrayInsercation(int arr[], int size, int element, int capacity, int index){
    // Code for Insercation
    if(size>=capacity){
        return -1;
    }

    for (int i = size; i >= index; i--){
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int arrayDeletion(int arr[], int size, int index){
    // Code for Deletion
    for (int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
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
    printf("Here are the array operation you can perform: \n");
    printf("0. Exit       1. Traversal        2. Insercation      3. Deletion");

    while (1){
        printf("\n");
        printf("Enter 0/1/2/3: ");
        scanf("%d", &query);

        if(query==0){
            printf("Exiting the loop! \n");
            break;
        }

        switch (query){
            case 1:{
                printf("\n");
                printf("  Traversal in Array: \n");
                printf("-------------------------\n");
                displayArray(arr, size);
                break;
            }

            case 2:{
                int element, index;

                printf("\n");
                printf(" Insertaion in Array: \n");
                printf("-------------------------");
                printf("\n");

                printf("Enter what you want to add: \n");
                scanf("%d", &element);
                printf("At which Index: \n");
                scanf("%d", &index);

                index = index - 1;

                printf("\n");
                arrayInsercation(arr, size, element, 100, index);
                printf("\n");
                
                size +=1;

                printf("\n");
                displayArray(arr, size);
                printf("\n");
                break;
            }

            case 3:{
                printf("\n");
                int index;

                printf("Enter which Index you want to delete: \n");
                scanf("%d", &index);
                index = index-1;
                printf("\n");

                arrayDeletion(arr, size, index);
                size -= 1;
                displayArray(arr, size);
                break;
            }
            
            default:
                printf("Something went Wrong!\n");
                break;
            }
    }

    return 0;
}