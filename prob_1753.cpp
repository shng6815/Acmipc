#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[20001];
int dis[20001];

void Dijkstra(int s, int n) {
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, s));
    dis[s] = 0;
    while (PQ.empty() == 0) {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < graph[Cur].size(); i++) {
            int Next = graph[Cur][i].first;
            int nCost = graph[Cur][i].second;
            if (dis[Next] > Cost + nCost) {
                dis[Next] = Cost + nCost;
                PQ.push(make_pair(-dis[Next], Next));
            }
        }
    }
}

int main() {
    int V, E, K;
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    for (int i = 1; i <= V; i++) dis[i] = INF;
    Dijkstra(K, V);

    for (int i = 1; i <= V; i++) {
        if (dis[i] == INF) {
            cout << "INF\n";
        } else
            cout << dis[i] << '\n';
    }

    return 0;
}