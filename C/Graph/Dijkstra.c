#define vertexNum 6
#define INF 0x3f3f3f3f
#include<stdio.h>
#include<stdlib.h>

struct MGraph{
    char *vertex;
    int **edge;
    int vexNum;
    int edgeNum;
};

void dijkstra(struct MGraph *MG,int start){
    int dist[vertexNum];
    int visited[vertexNum]={0};
    for(int i=0;i<vertexNum;i++){
        dist[i]=MG->edge[start][i];
    }
    int min_=start;
    int min=INF;
    while(1){
        min=INF;
        dist[start]=0;
        visited[min_]=1;
        int i;
        for(i=0;i<vertexNum;i++){
            if(dist[i]<min && !visited[i]){
                min=dist[i];
                min_=i;
            }
        }
        if(min==INF){
            break;
        }
        visited[min_]=1;
        for(i=0;i<vertexNum;i++){
            if(dist[i]>dist[min_] + MG->edge[min_][i]
            && MG->edge[min_][i]!=INF){
                dist[i]=dist[min_] + MG->edge[min_][i];
            }
        }
    }
    for(int i=0;i<vertexNum;i++){
        if (dist[i] == INF){
            printf("%c: unreachable\n", MG->vertex[i]);
            continue;
        }
        printf("%c:%d\n",MG->vertex[i],dist[i]);
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
    struct MGraph *MG=malloc(sizeof *MG);
    MG->vertex=malloc(vertexNum * sizeof *MG->vertex);
    char name[] = {'A','B','C','D','E','F'};
    MG->edge=malloc(vertexNum * sizeof *MG->edge);
    for(int i=0;i<vertexNum;i++){
        MG->vertex[i] = name[i];
        MG->edge[i]=malloc(vertexNum * sizeof **MG->edge);
        for(int j=0;j<vertexNum;j++){
            MG->edge[i][j]=matrix[i][j];
        }
    }
    dijkstra(MG,1);
    for(int i=0;i<vertexNum;i++){
        free(MG->edge[i]);
    }
    free(MG->vertex);
    free(MG->edge);
    free(MG);
}