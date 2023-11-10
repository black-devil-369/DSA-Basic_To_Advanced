#include<stdio.h>
#include<stdlib.h>
struct Graph{
    int v_count;
    int e_count;
    int **ptr;
};
struct Graph *creategraph(int vno,int eno){
    int v,u;
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    g->v_count = vno;
    g->e_count = eno;
    g->ptr = (int**)malloc(g->v_count * sizeof(int*));
    for(int i =0;i<vno;i++){
        g->ptr[i] = (int*)malloc(g->v_count * sizeof(int));
        for(int j=0;j<vno;j++){
            g->ptr[i][j] = 0;
        }
    }
    for(int k =1;k<=g->e_count;k++){
        printf("\nEnter the number of connecting edge ");
        scanf("%d %d",&v,&u);
        g->ptr[v][u] = 1;
        g->ptr[u][v] = 1;
    }
    return g;
}
void printgraph(struct Graph *g){
    for(int i =0;i<g->v_count; i++){
        for(int j = 0; j<g->v_count;j++){
            printf("%d",g->ptr[i][j]);
        }
        printf("\n");
    }
}
void destroyedgraph(struct Graph *g){
    for(int i =0;i<g->v_count;i++){
        free(g->ptr[i]);
    }
    free(g->ptr);
    free(g);
}
int main(){
    struct Graph *g1  = creategraph(5,6);
    printgraph(g1);
    destroyedgraph(g1);
    return 0;
}