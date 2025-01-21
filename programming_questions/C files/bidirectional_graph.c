/*
unidirectional graph
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct AdjList {
    struct Node *head;
};

struct Graph {
    int numberOfVertex;
    struct AdjList *arr;
};

/*
1. create node
2. create graph 
3. add Edge to the vertices
4. display path from source to destination
*/

struct Node* create_node(int vertex){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
};

struct Graph* create_graph(int numberOfvertex){

    struct Graph* graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numberOfVertex = numberOfvertex;

    graph->arr = (struct AdjList *)malloc(sizeof(struct AdjList)*numberOfvertex);

    for(int i=0;i<graph->numberOfVertex;i++){
        graph->arr[i].head = NULL;
    }

    return graph;
}


void addEdge(struct Graph *graph, int src, int dest){

    if (src >= graph->numberOfVertex || dest >= graph->numberOfVertex || src < 0 || dest < 0) 
    { 
        printf("Error: Invalid vertices (%d, %d)\n", src, dest); 
        return; 
    }

    if (graph->arr[src].head == NULL){
        struct Node *newNode = create_node(src);
        struct Node *adjNode = create_node(dest);

        graph->arr[src].head = newNode;
        graph->arr[src].head->next = adjNode;

    }else{
        struct Node *head = graph->arr[src].head;
        struct Node *node = head;
        while (node->next != NULL )
        {   
            if (node->vertex == dest) {
                return;
            }
            node = node->next;
        }
        struct Node *newNode = create_node(dest);
        node->next = newNode;
    }

}

//bidirectional graph
void addEdge_helper( struct Graph *graph, int src, int dest) {

    addEdge(graph, src, dest);
    addEdge(graph, dest, src);
}

void display_graph(struct Graph *graph){

    for(int i=0; i<graph->numberOfVertex; i++){
        struct Node *node = graph->arr[i].head;
        if (node != NULL){        
            while(node != NULL) {
                printf("%d-->",node->vertex);
                node = node->next;
            }
        printf("]\n");
        }else{
            printf("%d ---> []\n",i);
        }
    }
}



int main(){
    int numberOfVertex = 6;
    struct Graph *graph = create_graph(numberOfVertex);
    addEdge_helper(graph, 0, 1); 
    addEdge_helper(graph, 0, 4); 
    addEdge_helper(graph, 1, 2); 
    addEdge_helper(graph, 1, 3); 
    addEdge_helper(graph, 1, 4); 
    addEdge_helper(graph, 2, 3); 
    addEdge_helper(graph, 3, 4);

    display_graph(graph);

    return 0;

}







