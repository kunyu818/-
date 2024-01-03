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
            printf("ͼ�к��и�Ȩ�ػ�·\n");
            return;
        }
    }
    printf("��Դ�㵽����������·�����ȣ�\n");
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            printf("���� %d ��Դ������·������Ϊ INF\n", i);
        else
            printf("���� %d ��Դ������·������Ϊ %d\n", i, dist[i]);
    }
}
int main() {
    int V, E;
    printf("�����붥�����V�ͱߵ�����E��\n");
    scanf("%d %d", &V, &E);
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    printf("������ÿ���ߵ���㡢�յ��Ȩ�أ��ÿո�ָ�����\n");
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

