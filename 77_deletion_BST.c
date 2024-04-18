#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

struct Node* inOrderPredecesser(struct Node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
};

struct Node* deleteNode(struct Node* root, int value){
    struct Node* iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right==NULL){
        free(root);
    }

    // Searching the Node to be deleted
    if(value<root->data){
        deleteNode(root->left, value);
    } else if(value>root->data){
        deleteNode(root->right, value);
    } else{
        iPre = inOrderPredecesser(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
};

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
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

    printf(" Printing Node\n");
    printf("----------------\n");
    inOrder(n);

    printf("\n");
    int value;
    printf("Enter the value you want to delete: ");
    scanf("%d", &value);
    deleteNode(n, value);
    printf("\n");
    printf(" After Deleting\n");
    inOrder(n);

    return 0;
}