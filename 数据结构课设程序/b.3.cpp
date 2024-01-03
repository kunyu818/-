#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Edge {
    int src, dest, weight;
};
void bellmanFord(struct Edge* edges, int V, int E, int src) {
    int dist[V];
    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("图中含有负权重环路\n");
            return;
        }
    }
    printf("从源点到各顶点的最短路径长度：\n");
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            printf("顶点 %d 到源点的最短路径长度为 INF\n", i);
        else
            printf("顶点 %d 到源点的最短路径长度为 %d\n", i, dist[i]);
    }
}
int main() {
    int V, E;
    printf("请输入顶点个数V和边的条数E：\n");
    scanf("%d %d", &V, &E);
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    printf("请输入每条边的起点、终点和权重（用空格分隔）：\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }
    int src = 0; 
    bellmanFord(edges, V, E, src);
    free(edges);
    return 0;
}

