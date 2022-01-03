#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

pedge add_edge (pnode *head, pnode *curr_node){
    int dest;
    if (scanf("%d",&dest) == 1) // can read the dest of the edge
    {
        pedge new_edge = getEdge ((*curr_node)->edges,dest);
        if (new_edge == NULL)
        {
        new_edge = (pedge)malloc(sizeof(edge)); // alloc space for new edge.
                    if(new_edge == NULL ){
                    printf("error - no more memory");
                    return NULL;}
        
        pnode temp_pointer = getNode(*head, dest); // if the dest node dosen't excist creat new node;
            if (temp_pointer == NULL) temp_pointer = add_node(head, dest);

        new_edge->endpoint = temp_pointer;
        (scanf("%d",&(new_edge->weight)));
        new_edge->next = (*curr_node)->edges;
        (*curr_node)->edges = new_edge;
        //printEdge(new_edge);
        return (*curr_node)->edges;
        }
        else{
        (scanf("%d",&(new_edge->weight)));
        printf("weight of %d changed to %d", (*curr_node)->ID, new_edge->weight);
        printEdge(new_edge);
        return new_edge;
        }
    }
    return NULL; 
}


pedge getEdge(pedge head,int id){
  
    pedge temp = head;
    while (temp)
    {
        if (temp->endpoint->ID == id)
            return temp;
        temp = temp->next;
          
    }
    return NULL;
}

void delete_all_edges(pedge *current){
    
    while(*current){
    pedge handle= *current;
    *current = handle->next;
    free(handle);     
    }
    
}
void printEdges(pedge etemp){
       while (etemp != NULL)
       {
            printf("edge to %d - ",etemp->endpoint->ID);
            printf("weight %d; ",etemp->weight);
            etemp = etemp->next;
       } 
       
}
void printEdge(pedge etemp){
    printf(" new edge: ");
    printf("to %d - ",etemp->endpoint->ID);
    printf("weight %d;",etemp->weight);
}



void delete_edge(pnode *head ,int id){
    if(getEdge((*head)->edges,id)==NULL) return;
    // if it's the first
    pedge pn = (*head)->edges;
    if (pn->endpoint->ID == id){ 
    (*head)->edges = (*head)->edges->next;
    free (pn);
    return;
    }
    //else find it
    while (pn->next->endpoint->ID != id){
        pn = pn->next;
    }
    pedge handle = pn->next->next;
    free (pn->next);
    pn->next = handle;
}