#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct Node {
    int dest;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node** array;
};
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;

    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}
struct Graph* matrixToAdjList(int matrix[][MAX_NODES], int V) {
    struct Graph* graph = createGraph(V);

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            if (matrix[i][j])
                addEdge(graph, i, j);

    return graph;
}
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* temp = graph->array[v];
        printf("\n 顶点的邻接表 %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int matrix[][MAX_NODES] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    int V = 4;
    struct Graph* adjList = matrixToAdjList(matrix, V);
    printGraph(adjList);
    return 0;
}

