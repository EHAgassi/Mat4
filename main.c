#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
//hjhjkjlk
int main(int argc, char const *argv[])
{
    pnode phead = NULL;
    FILE *stream;
    if((stream = fopen("input1.txt", "r"))==NULL){
        printf("wrong");
        return 1;
    }
    build_graph(&phead,stream);
    return 0;
}

void build_graph(pnode *phead,FILE *stream){
    char curr;
    while(!feof(stream)){
        curr = fgetc(stream);
        switch (curr)
            {
            case 'A':;
            int num_nodes;
            if(scanf("%d",&num_nodes)==1);
            for (size_t i = 0; i < num_nodes; i++)
                init_graph(phead);   
            printGraph(phead);
            continue;
            case 'B':; 
                new_node(phead);
                continue;
            case 'D':;
                int id;
                scanf("%d",&id);
                delete_node(phead,id);
                continue;
            case 'T':;
                int answer = TSP(phead);
                printf("TSP shortest path: %d ",answer);
                continue;
            case 'S':;
            int a,b,ans;
                scanf("%d %d",&a,&b);
                ans = dijkstra(phead,a,b);
                printf("Dijsktra shortest path: %d ",ans);
                continue;
            default:
                break;
            }

    }

    printf("\n");

}