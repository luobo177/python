#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
};

void push(struct queue **header,struct queue **tail,int data){
    struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data=data;
    newnode->next=NULL;
    if(*header==NULL){
        printf("empty queue,will init the first node\n");
        *header = *tail = newnode;
        return;
    }
    (*tail)->next=newnode;
    (*tail)=newnode;
}

void pop(struct queue **header,struct queue **tail){
    if((*header)==NULL){
        printf("empty queue ,fuck you");
        return;
    }
    struct queue *temp = *header;
    (*header)=(*header)->next;
    if((*header)==NULL){
        *tail = NULL;
    }
    free(temp);
}

void printQueue(struct queue *header){
    if(header == NULL){
        printf("empty queue");
        return;
    }
    struct queue *temp = header;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct queue *header,*tail;
    header = tail =NULL;
    push(&header,&tail,1);
    push(&header,&tail,2);
    push(&header,&tail,3);
    pop(&header,&tail);
    pop(&header,&tail);
    pop(&header,&tail);
    push(&header,&tail,1);
    printQueue(header);
    return 0;
}