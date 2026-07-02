#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
enum lf{
    LEFT,
    RIGHT
};
struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

void addNode(struct treeNode *parent,enum lf side,int data){
    if(parent == NULL){
        printf("invalid parent");
        return;
    }
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->data = data;
    newNode->left=newNode->right=NULL;
    if(side == LEFT){
        if(parent->left!=NULL){
            printf("the left son node already exist");
            free(newNode);
            return;
        }
        parent->left=newNode;
    }else{
        if(parent->right!=NULL){
            printf("the right son node already exist");
            free(newNode);
            return;
        }
        parent->right=newNode;
    }
}

void preOrder(struct treeNode *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct treeNode *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void postOrder(struct treeNode *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct treeNode *root = (struct treeNode*)malloc(sizeof(struct treeNode));
    root->left=root->right=NULL;
    root->data=0;
    addNode(root, LEFT, 10);

    addNode(root, RIGHT, 20);

    addNode(root->left, LEFT, 30);

    addNode(root->left, RIGHT, 40);

    addNode(root->right, LEFT, 50);

    addNode(root->right, RIGHT, 60);

    addNode(root->left->right, LEFT, 70);

    addNode(root->right->right, RIGHT, 80);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
}