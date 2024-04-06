#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// CreateNode Function
struct Node* createNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

// inOrder Traversal
void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Insert Function
void insert(struct Node* root, int key){
    struct Node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Can't Add %d element already in BST\n", key);
            return;
        } else if(key<root->data){
            root = root->left;
        } else{
            root = root->right;
        }
    }

    struct Node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    } else{
        prev->right = new;
    }
}

int main(){
    // CreateNode 
    struct Node* n = createNode(1);
    struct Node* n1 = createNode(2);
    struct Node* n2 = createNode(3);
    struct Node* n3 = createNode(4);
    struct Node* n4 = createNode(5);


    // Conicting Node
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;

    while(1){
        printf("\n");
        printf(" PreOrder Traversal\n");
        printf("---------------------\n");
        inOrder(n);
        printf("\n");

        int key;
        printf("Enter the key: ");
        scanf("%d", &key);
        insert(n, key);
        printf("\n");
        printf(" PreOrder Traversal\n");
        printf("---------------------\n");
        inOrder(n);
        printf("\n");
    }

    return 0;
}