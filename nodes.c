#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

void init_graph(pnode *head){
    char n;
    scanf("%c",&n);
    printf("%c? ", &n);
    int id;
    pnode curr_node;
    
    scanf ("%d",&id); 
    curr_node = getNode(*head, id);
    if (curr_node == NULL) curr_node = add_node(head,id);
    pedge pd = NULL;
    do {pd = add_edge (head,&curr_node);}
    while(pd != NULL);
    
}


void new_node(pnode *head){
    int id;
    pnode curr_node;
    
    scanf ("%d",&id); 
    curr_node = getNode(*head, id);
    if (curr_node == NULL) curr_node = add_node(head,id);
    else delete_all_edges(&(getNode(*head,id)->edges));
    pedge pd = NULL;
    do {pd = add_edge (head,&curr_node);}
    while(pd != NULL);
}


pnode add_node(pnode *head, int id){
pnode new_node = getNode(*head,id);
    if (new_node == NULL)
    {       
        pnode temp = (pnode)malloc(sizeof(node));
                if(temp == NULL){
                    printf("error");
                    return NULL;}
        temp->ID = id;
        temp->next = *head;
        *head = temp;

       // printf("\n*node #%d added: " , temp->ID); 
        // printGraph(head);
         
        return temp;
    }
    // printGraph(head);
    
return new_node;  
}

pnode getNode(pnode head, int id){
    while (head != NULL)
    {
        if (head->ID == id)
            return head;
        head = head->next;
    }
    return NULL;
}


void printGraph(pnode *head){ //for self debug
 printf("\nGraph: ");
    pnode temp = *head;
    while (temp!=NULL)
    {
        printf("Node %d: " , temp->ID);
        printEdges(temp->edges);
        temp = temp->next;
    }
    printf("\n");
}

void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

void delete_node(pnode *head,int id){
    if(getNode(*head,id)==NULL) return;
    
    pnode temp = *head;
        while(temp){
            delete_edge(&temp,id);
            temp = temp->next;
        }
        
    pnode pn = *head;
     // if it's the first
    if (pn->ID == id){
        *head = pn->next;
        delete_all_edges(&(pn->edges));
        free (pn);
    }else{
    // else find the node
    while (pn->next->ID != id){
        pn = pn->next;
    }
    delete_all_edges(&(pn->next->edges));
    pnode handle = pn->next->next;
    free (pn->next);
    pn->next = handle;
    }
    
}

void delete_all_nodes(pnode *head){
    pnode pn = *head;
    while (pn != NULL){
        delete_all_edges(&pn->edges);
        pn = *head;
        *head = pn->next;
        free (pn);
    }
}

