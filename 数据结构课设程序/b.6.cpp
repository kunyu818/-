#include<iostream>
#include<queue>
using namespace std;
struct Step {
    int x, y;
    int steps;
};
int a[100][100], book[100][100] = {0};
int Next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<Step> q;
Step pre[100][100];
void print(int x, int y) {
    if (x == 0 && y == 0) {
        printf("(0, 0)\n");
        return;
    }
    print(pre[x][y].x, pre[x][y].y);
    printf("(%d, %d)\n", x, y);
    return;
}
int bfs(int N, int M) {
    Step nd;
    nd.x = 0, nd.y = 0, nd.steps = 0;
    book[0][0] = 1;
    q.push(nd);
    while (!q.empty()) {
        Step s = q.front();
        if (s.x == N - 1 && s.y == M - 1) {
            print(N - 1, M - 1);
            return s.steps;
        }
        for (int i = 0; i < 4; i++) {
            int nx = s.x + Next[i][0], ny = s.y + Next[i][1], step = s.steps + 1;
            if ((nx < N && nx >= 0) && (ny < M && ny >= 0) && book[nx][ny] == 0 && a[nx][ny] == 0) {
                Step p;
                p.x = nx, p.y = ny, p.steps = step;
                book[nx][ny] = 1;
                pre[nx][ny].x = s.x, pre[nx][ny].y = s.y;
                q.push(p);
            }
        }
        q.pop();
    }
    return -1;
}
int dfs(int x, int y, int N, int M, int steps) {
    if (x == N - 1 && y == M - 1) {
        return steps;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + Next[i][0], ny = y + Next[i][1];
        if ((nx < N && nx >= 0) && (ny < M && ny >= 0) && book[nx][ny] == 0 && a[nx][ny] == 0) {
            book[nx][ny] = 1;
            int result = dfs(nx, ny, N, M, steps + 1);
            if (result != -1) {
                return result;
            }
        }
    }
    return -1;
}
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    int bfsSteps = bfs(N, M);
    cout << "BFS算法求得的最短路径步数: " << bfsSteps << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            book[i][j] = 0;
    book[startX][startY] = 1;
    int dfsSteps = dfs(startX, startY, N, M, 0);
    cout << "递归算法求得的最短路径步数: " << dfsSteps << endl;
    return 0;
}

