#include<stdio.h>
#include<stdlib.h>

// Graph
int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

// DFS Implementation  
void DFS(int i){
    printf("%d\t", i);
    visited[i] = 1;
    for(int j = 0; j<7; j++){
        if(a[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(){
    int query;
    printf("Enter the number from where you want to start: ");
    scanf("%d", &query);
    
    DFS(query);
    return 0;
}