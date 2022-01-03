#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include <limits.h>

static int length = INT_MAX;

int count(pnode *head){
int sum =0;
pnode temp = *head;
while(temp != NULL){
    temp = temp->next;
    sum++;
}
return sum;
}


void init_dist_and_visit(pnode *head){
    pnode temp = *head;
    while(temp != NULL){
        temp->dist = INT_MAX;
        temp->visited = 0;
        temp = temp->next;
    }
}



int dijkstra (pnode *head, int src, int dest){

    // initilze the data
    init_dist_and_visit(head);

    // mark the first
    if(getNode(*head, src)) getNode(*head, src)->dist = 0;
    while(is_more(head))
    {
        pnode current = min_dist(head);
        if (!current) return -1;
        pedge p = current->edges;
        while(p)
        {
            if (p->endpoint->visited==0)
            {
                int calc = current->dist + p->weight;
               // printf("node %d: to node:%d calc: %d; ",current->ID,p->endpoint->ID, calc);
               // printf("dist %d + weight %d,", p->endpoint->dist,p->weight);
                if (calc < p->endpoint->dist)
                {
                    getNode(*head,p->endpoint->ID)->dist = calc;
                    getNode(*head,p->endpoint->ID)->prev = current;
                    printf("dist changed to %d ", calc);
                }
            }
        p = p-> next;
        } 
    current -> visited = 1;
    }
    int output = print_path(head,src, dest, count(head));
    return output; 
}

pnode min_dist(pnode *head){
pnode temp = *head, answer = NULL;
int minimal = INT_MAX;
    while(temp){
        if(temp->visited == 0) {
            if( temp->dist< minimal){
            minimal = temp->dist;
            answer = temp;
            printf("%d is minimal now ", temp->ID);
            }
        }
        temp = temp->next;
    }
if(answer == NULL){
   return NULL;
}
return answer;
}

int is_more(pnode *head){
    pnode temp = *head;
    while(temp)
    {
        if( !temp->visited ) return 1;
        temp = temp->next;
    }
return 0;
}
int print_path(pnode *head,int src, int dest, int numOfNodes){
    pnode temp = getNode(*head, dest);
    
    printf("temp -> dist %d ",temp -> dist);

    if(temp->dist== INT_MAX) return -1;

    int count = 0;
    
    while(temp->ID!=src){
        count = count + getEdge(temp->prev->edges, temp->ID)->weight;
        temp= temp->prev;
    }
    
    return count;
}





int TSP(pnode *head){
    int numOfNodes;
    scanf("%d",&numOfNodes);
    int *num_arr = get_num(numOfNodes);
    length = INT_MAX;
    get_permutation(head,num_arr ,0, numOfNodes);
    if (length == INT_MAX) return -1;  
    return length;
}

int* get_num(int numOfNodes){
    int* arr = (int*)malloc(sizeof(int)*numOfNodes);
    for (size_t i = 0; i < numOfNodes; i++)
    {
     scanf("%d",&arr[i]);
    }
    return arr;
}
int get_permutation(pnode *head ,int* arr , int start, int end){
    int sum = INT_MAX;
    if (start == end){
        printPrem(arr,end); 
        sum = calc_prem(head,arr,end);
        printf("num: %d sum: %d ",end, sum);  
        if (sum!= -1 && sum < length) length = sum;
        return 0;
    }
        get_permutation(head , arr ,start+1, end);  
        for (int i = start; i < end; i++)
        {
            if ((arr+start) == (arr+i)) continue;
            Swap((arr+start), (arr+i));
            get_permutation(head , arr ,start+1, end);
            Swap((arr+start), (arr+i));
            /* printPrem(arr, end); */
        } 
 return length;
}

int calc_prem (pnode *head, int* perm, int length){
int sum = 0;
for (size_t i = 0; i < length-1; i++){
    printf("%d - %d ;",perm[i],perm[i+1]);
    int dist =  dijkstra(head ,perm[i],perm[i+1]);
    if (dist != -1) sum = sum + dist;
    else return dist;
}
return sum;
}


void Swap(int *a, int *b)
{
    if (*a == *b) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* copy( int *arr, int lenght){
    int *temp = (int*)malloc(sizeof(int)*lenght);
    for (size_t i = 0; i < lenght; i++) temp[i] = arr[i];
    return temp;
}
void printPrem(int *arr, int end){
printf("\nPrem: ");
for (size_t i = 0; i < end; i++)
{
    printf("%d ", arr[i]);
}
}