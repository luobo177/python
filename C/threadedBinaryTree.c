#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

enum lf{
    LEFT,
    RIGHT
};

struct threadedBT{
    int data;
    bool leftEx;
    bool rightEx;
    struct threadedBT *left;
    struct threadedBT *right;
};

struct threadedBT *initNode(int data){
    struct threadedBT *newNode = (struct threadedBT*)malloc(sizeof(struct threadedBT));
    newNode->data = data;
    newNode->leftEx=0;
    newNode->right=0;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void addNode(struct threadedBT *parent,enum lf side,int data){
    if(parent == NULL){
        printf("invalid parent");
        return;
    }
    struct threadedBT *newNode = initNode(data);
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

void inOrderThreadTree(struct threadedBT *root,struct threadedBT **p){//p denote the node before
    if(root==NULL){
        return;
    }
    inOrderThreadTree(root->left,p);
    if(root->left==NULL){
        root->leftEx=1;
        root->left=*p;
    }
    if((*p)!=NULL && (*p)->right==NULL){
        (*p)->rightEx=1;
        (*p)->right=root;
    }
    (*p)=root;
    inOrderThreadTree(root->right,p);
}

int main(){
    struct threadedBT *root = initNode(10);
    struct threadedBT *pre = NULL;
    addNode(root, LEFT, 10);

    addNode(root, RIGHT, 20);

    addNode(root->left, LEFT, 30);

    addNode(root->left, RIGHT, 40);

    addNode(root->right, LEFT, 50);

    addNode(root->right, RIGHT, 60);

    addNode(root->left->right, LEFT, 70);

    addNode(root->right->right, RIGHT, 80);
    inOrderThreadTree(root,&pre);
    printf("%d",root->left->data);
}