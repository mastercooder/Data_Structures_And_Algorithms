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


struct Node* searchIter(struct Node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        } else if(key <= root->data){
            root = root->left;
        } else{
            root = root->right;
        }
    }
    return NULL;
}


int main(){
    // creating Node
    struct Node* p = createNode(5);
    struct Node* p1 = createNode(3);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(1);
    struct Node* p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \    
    //  1   4

    // Connecting Node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf(" Node has been create successfully: \n");
    printf("------------------------------------\n");
    printf("\n");

    // searching...
    int key;
    printf("Enter the key you want to searchIter: ");
    scanf("%d", &key);
    struct Node* n = searchIter(p, key);
    if(n!=NULL){
        printf("Found %d\n", n->data);
    }else{
        printf("Element not Found\n");
    }

    printf("\n");
    return 0;
}