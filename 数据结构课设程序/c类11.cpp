#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int parent[10];
int n,m;
int i,j;
struct edge{
	int u,v,w;
}edges[10];
void UFset(){
	for(i=1; i<=n; i++) parent[i] = -1;
}
int find(int i){
	int temp;
	for(temp = i; parent[temp] >= 0; temp = parent[temp]);
	while(temp != i){
		int t = parent[i];
		parent[i] = temp;
		i = t;
	}
	return temp;
}
void merge(int a,int b){
	int r1 = find(a);
	int r2 = find(b);
	int tmp = parent[r1] + parent[r2];
	if(parent[r1] > parent[r2]){
		parent[r1] = r2;
		parent[r2] = tmp;
	}else{
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}
void kruskal(){
	int sumWeight = 0;
	int num = 0;
	int u,v;
	UFset();
	for(int i=0; i<m; i++)
	{
		u = edges[i].u;
		v = edges[i].v;
		if(find(u) != find(v)){
			printf("加入边：%d %d,权值： %d\n", u,v,edges[i].w);
			sumWeight += edges[i].w;
			num ++;
			merge(u, v);
		}
	}
	printf("weight of MST is %d \n", sumWeight);
}
int cmp(const void * a, const void * b){
	edge * e1 = (edge *)a;
	edge * e2 = (edge *)b;
	return e1->w - e2->w;
}
int main() {
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d %d", &edges[i].u,  &edges[i].v,  &edges[i].w);
	}
	qsort(edges, m, sizeof(edge), cmp);
	kruskal();
	return 0;
}
