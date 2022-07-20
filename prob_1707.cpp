#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// int graph[20001][20001];
int visit[20010];
vector<int> graph[20010];
queue<int> q;
int flag;

void BFS(int v, int start) {
    visit[start] = 1;
    q.push(start);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curState = visit[q.front()];
            int u = q.front();
            q.pop();
            for (int j = 0; j < graph[u].size(); j++) {
                if (!visit[graph[u][j]]) {
                    if (curState == 1)
                        visit[graph[u][j]] = 2;
                    else
                        visit[graph[u][j]] = 1;

                    q.push(graph[u][j]);
                } else if (visit[graph[u][j]] == curState) {
                    flag = false;
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (!visit[i]) BFS(v, i);
    }
}

void reset(int v) {
    for (int i = 0; i <= v; i++) {
        visit[i] = 0;
    }

    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;
        for (int k = 1; k <= V; k++) graph[k].clear();

        for (int i = 0; i < E; i++) {
            flag = true;
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        BFS(V, 1);
        if (flag) {
            cout << "YES" << '\n';
        } else
            cout << "NO" << '\n';

        reset(V);
    }
    return 0;
}