#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
};

int getBalanceFactor(struct Node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b){
    return (a>b)?a:b;
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* Node, int data){
    if(Node==NULL){
        return createNode(data);
    }

    if(data < Node->data){
        Node->left = insert(Node->left, data);
    } else if(data > Node->data){
        Node->right = insert(Node->right, data);
    }

    Node->height = 1 + max(getHeight(Node->left), getHeight(Node->right));
    int bf = getBalanceFactor(Node);

    // Left to Left Rotation
    if(bf>1 && data<Node->left->data){
        return rightRotate(Node);
    }

    // Right to Right Rotation 
    if(bf<-1 && data>Node->right->data){
        return leftRotate(Node);
    }

    // Left to Right Rotation
    if(bf>1 && data>Node->left->data){
        Node->left = leftRotate(Node->left);
        return rightRotate(Node);
    }

    // Right to Left Rotation
    if(bf<-1 && data<Node->right->data){
        Node->right = rightRotate(Node->right);
        return leftRotate(Node);
    }

    return Node;
}

void preOrder(struct Node* root){
        if(root!=NULL){
            printf("%d ", root->data);
            preOrder(root->left);
            preOrder(root->right);
        }
    }

int main(){
    struct Node* root = NULL;

    int size, data;
    printf("Enter the size of Node: ");
    scanf("%d", &size);

    for(int i = 0; i<size; i++){
        printf("%d: ", i+1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("The Traversal will be:\n");
    preOrder(root);

    return 0;
}