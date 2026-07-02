#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define vertexNum 6
#define INF 0x3f3f3f3f
struct MGraph{
    int **edge;
};

int min(int a,int b){
    return (a<b)?a:b; 
}

void floyd(struct MGraph *MG){
    int **edge=MG->edge;
    int dist[vertexNum][vertexNum]={0};
    int path[vertexNum][vertexNum];
    memset(path,-1,sizeof(path));
    for(int i=0;i<vertexNum;i++){
        for(int j=0;j<vertexNum;j++){
            dist[i][j]=MG->edge[i][j];
        }
    }
    for(int k=0;k<vertexNum;k++){
        for(int i=0;i<vertexNum;i++){
            for(int j=0;j<vertexNum;j++){
                if(dist[k][j]!=INF&&
                dist[i][k]!=INF){
                    int temp = dist[i][j];
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    if(dist[i][j]!=temp){
                        path[i][j]=k;
                    }
                }
            }
        }
    }
    for(int i=0;i<vertexNum;i++){
        for(int j=0;j<vertexNum;j++){
            if(dist[i][j]!=INF)
            printf("%d ",dist[i][j]);
            else
            printf("INF ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<vertexNum;i++){
        for(int j=0;j<vertexNum;j++){
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    int matrix[6][6] = {
    {  0,   2,   5, INF, INF, INF }, // A
    {  2,   0,   1,   4, INF, INF }, // B
    {  5,   1,   0,   1, INF, INF }, // C
    { INF,  4,   1,   0,   3, INF }, // D
    { INF, INF, INF,  3,   0, INF }, // E
    { INF, INF, INF, INF, INF,   0 } // F（完全孤立）
    };
    struct MGraph *MG=malloc(sizeof(struct MGraph));
    MG->edge=malloc(vertexNum * sizeof(*MG->edge));
    for(int i=0;i<vertexNum;i++){
        MG->edge[i]=malloc(vertexNum * sizeof(**MG->edge));
        for(int j=0;j<vertexNum;j++){
            MG->edge[i][j]=matrix[i][j];
        }
    }
    floyd(MG);
}