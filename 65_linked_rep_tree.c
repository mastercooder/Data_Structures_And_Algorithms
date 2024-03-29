#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* creatNode(int data){
    // Creating and allocating the Node
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    // Setting the data
    n->data = data;
    // Setting the left and right Children.
    n->left = NULL;
    n->right = NULL;
    // Returning the Node
    return n;
}
int main(){
    // Constructing the root Node
    // struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    // p->left = NULL;
    // p->data = 1;
    // p->right = NULL;

    // Constructing the second Node.
    // struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
    // p1->left = NULL;
    // p1->data = 2;
    // p1->right = NULL;
    
    // Constructing the third Node.
    // struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
    // p2->left = NULL;
    // p2->data = 3;
    // p2->right = NULL;

    //  Creating the Node with the function.
    struct Node* p = creatNode(2);
    struct Node* p1 = creatNode(1);
    struct Node* p2 = creatNode(4);

    // Linked the Node with left and right children.
    p->left = p1;
    p->right = p2;

    return 0;
}