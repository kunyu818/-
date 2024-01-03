#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_NODES 100
struct Node {
    int dest;
    struct Node* next;
};
struct List {
    struct Node *head;
};
struct Graph {
    int V;
    struct List* array;
};
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
void DFS(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    struct Node* temp = graph->array[v].head;
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            DFS(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}
bool isStronglyConnected(struct Graph* graph) {
    bool visited[MAX_NODES];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    DFS(graph, 0, visited);
    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    struct Graph* reverseGraph = (struct Graph*)malloc(sizeof(struct Graph));
    reverseGraph->V = graph->V;
    reverseGraph->array = (struct List*)malloc(graph->V * sizeof(struct List));
    for (int i = 0; i < graph->V; i++) {
        reverseGraph->array[i].head = NULL;
    }
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->array[v].head;
        while (temp != NULL) {
            addEdge(reverseGraph, temp->dest, v);
            temp = temp->next;
        }
    }
    DFS(reverseGraph, 0, visited);
    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}
int main() {
    int numNodes = 5; 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = numNodes;
    graph->array = (struct List*)malloc(numNodes * sizeof(struct List));

    for (int i = 0; i < numNodes; i++) {
        graph->array[i].head = NULL;
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 2);
    if (isStronglyConnected(graph)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

