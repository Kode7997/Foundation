#include<stdlib.h>
#include<stdio.h>


int** create_matrix(int v){

    int **matrix = (int **)malloc(v * sizeof(int *));
    for(int i=0;i<v;i++){
        matrix[i] = (int *)calloc(v, sizeof(int));
    }

    return matrix;
}

void display(int** matrix) {
    
    for(int i =0;i<5;i++) {
        for(int j=0;j<5;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int **graph, int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
    return;
}

void DFS(int **graph, int v, int *visited, int *path, int *pathIndex) {

    visited[v] = 1;
    path[(*pathIndex)++] = v;

    for (int i=0;i<5;i++){
        if ((graph[v][i] == 1) && (!visited[i])){
            DFS(graph, i,visited, path, pathIndex);
        }
    }
}


int main(){

    int **graph = create_matrix(5);
    display(graph);

   addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    printf("\n");
    display(graph);

    int path[5];
    int pathIndex = 0;
    int visited[5] = {0};

    DFS(graph, 0, visited, path, &pathIndex);
      printf("\n");
    for (int i = 0; i < pathIndex; i++)
    {
        printf("%d ",path[i]);
    }
    


    
}





