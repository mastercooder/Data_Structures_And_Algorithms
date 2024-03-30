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

void Operation(){
    printf("\n");
    printf("1: preOrder\n");
    printf("2: postOrder\n");
    printf("3: inrder\n");
    printf("\n");
}

void preOrder(struct Node* root){
    if(root!=NULL){     
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}   

int main(){
    // Making Node
    struct Node* p = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(5);
    struct Node* p4 = createNode(2);

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    
    // Connecting Node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    while(1){
        Operation();
        printf("\n");
        int query;
        printf("Enter the Number || 0 to exit: ");
        scanf("%d", &query);
        
        if(query==0){
            printf("\n");
            printf("Exiting the Loop\n");
            printf("\n");
            return -1;
        }

        switch(query){
            case 1:{
                printf("\n");
                printf(" preOrder\n");
                printf("------------\n");
                preOrder(p);
                printf("\n");
                break;
            }

            case 2:{
                printf("\n");
                printf(" postOrder\n");
                printf("------------\n");
                postOrder(p);
                printf("\n");
                break;
            }

            case 3:{
                printf("\n");
                printf(" inOrder\n");
                printf("------------\n");
                inOrder(p);
                printf("\n");
                break;
            }

            default:
                printf("Something Went Wrong!\n");
        }
    }

    return 0;
}
