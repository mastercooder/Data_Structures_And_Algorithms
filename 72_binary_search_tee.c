#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node* root){
    static struct Node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else{
        return 1;
    } 
}

struct Node* createNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    // makeNOde
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

    // linkNOde
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\n");
    printf(" inOrder\n");
    inOrder(p);
    printf("\n");

    printf("\n");
    printf(" isBST\n");
    printf("----------\n");
    if(isBST(p)){
        printf("The Binary tree is BST\n");
    } else{
        printf("The Binary tree is not BST\n");
    }

    printf("\n");
    return 0;
}