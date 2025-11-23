#include<stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct AdjList {
    struct Node *head;
};

struct Graph{
    struct AdjList *arr;
    int numberOfVertices;
};


struct Graph* create_graph(int num){

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numberOfVertices = num;

    graph->arr = (struct AdjList *)malloc(graph->numberOfVertices * sizeof(struct AdjList));

    for (int i = 0; i < graph->numberOfVertices; i++)
    {
        graph->arr[i].head = NULL;
    }

    return graph;

}

struct Node* create_node(int vertex){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}


void addEdge(struct Graph *graph, int src, int dest){

    struct Node *srcNode = create_node(src);
    struct Node *destNode = create_node(dest);

    if ((src >= graph->numberOfVertices) || (src < 0 )) {
        return;
    }

    if ((dest >= graph->numberOfVertices) || (dest < 0 )) {
        return;
    }

    if (graph->arr[src].head == NULL) {
        graph->arr[src].head = destNode;
    }else{
        struct Node *node = graph->arr[src].head;
        while (node->next != NULL)
        {   
            node = node->next;
        }
        node->next = destNode;
    }

    if (graph->arr[dest].head == NULL) {
        graph->arr[dest].head = srcNode;
    }else{
        struct Node *node = graph->arr[dest].head;
        while (node->next != NULL)
        {   
            node = node->next;
        }
        node->next = srcNode;
    }

    return;
}

void dfs_graph(struct Graph *graph, int vertex, int *visited){

    struct Node *adjNode = graph->arr[vertex].head;
    struct Node *temp = adjNode;
    //printf("hello\n");
    printf("%d -->", vertex);
    visited[vertex] = 1;

    while (temp != NULL)
    {
        int connected_vertex = temp->vertex;
        if (visited[connected_vertex] == 0){
            dfs_graph(graph, connected_vertex, visited);
        }

        temp = temp->next;
    }
    
    
    return;
}


int main(){
    struct Graph *graph = create_graph(5);

    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4);

    int *visited = (int *)calloc(5, sizeof(int));
    dfs_graph(graph, 0, visited);

}