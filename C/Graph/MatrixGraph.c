#define vertexNum 5
int visited[vertexNum]={0};
#include<stdio.h>
#include<stdlib.h>
struct MGraph{
    int *vertex;
    int **edge;
    int vexNum;
    int edgeNum;
};

struct bfsQueue{
    int queue[vertexNum];
    int head;
    int tail;
    int size;
};


void dfs(struct MGraph *MG,int start){
    visited[start] = 1;
    for(int i=0;i<vertexNum;i++){
        if(!visited[i] &&MG->edge[start][i]){
            dfs(MG,i);
        }
    }
}

void queue_add(struct bfsQueue *q,int num){//
    if(q->size==vertexNum){
        printf("full queue");
        return;
    }
    q->queue[q->tail]=num;
    q->tail=(q->tail+1)%vertexNum;
    q->size++;
    return;
}

int queue_pop(struct bfsQueue *q){
    if(q->size==0){
        printf("empty queue");
        return -1;
    }
    int temp = q->queue[q->head];
    q->head=((q->head+1)%vertexNum);
    q->size--;
    return temp;
}

void bfs(struct MGraph *MG,int start){
    struct bfsQueue *q=malloc(sizeof (struct bfsQueue));
    for(int i=0;i<vertexNum;i++){//initialization queue
        q->queue[i]=0;
    }
    q->head=q->tail=q->size=0;
    visited[start]=1;
    queue_add(q,start);
    while(q->size){
        int t=queue_pop(q);
        for(int i=0;i<vertexNum;i++){
            if(MG->edge[t][i] && !visited[i]){
                queue_add(q,i);
                visited[i]=1;
            }
        }
    }
    for(int j=0;j<vertexNum;j++)
    printf("第%d 连接情况%d\n",j,visited[j]);
    free(q);
}

int main(){
    int matrix[vertexNum][vertexNum]={
        {0,1,0,0,0},
        {1,0,0,1,1},
        {1,0,0,0,1},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };
    struct MGraph *MG=malloc(sizeof *MG);
    MG->vertex=malloc(vertexNum * sizeof *MG->vertex);
    MG->edge=malloc(vertexNum * sizeof *MG->edge);
    for(int i=0;i<vertexNum;i++){
        MG->vertex[i]=i;
        MG->edge[i]=malloc(vertexNum * sizeof **MG->edge);
        for(int j=0;j<vertexNum;j++){
            MG->edge[i][j]=matrix[i][j];
        }
    } 
    MG->edgeNum=5;
    MG->vexNum=vertexNum;
    //以上为定义邻接矩阵
    bfs(MG,0);
    for(int i=0;i<vertexNum;i++){
         free(MG->edge[i]);
}
    free(MG->edge);
    free(MG->vertex);
    free(MG);
}
