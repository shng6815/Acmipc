#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> bridge;
int visit[101];
queue<int> q;
int ans;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        bridge.insert({x, y});
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        bridge.insert({u, v});
    }

    visit[1] = 1;
    q.push(1);
    ans = 0;

    while (!q.empty()) {
        int size = q.size();

        if (visit[100]) {
            break;
        }

        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            for (int j = 1; j <= 6; j++) {
                if (cur + j <= 100 && !visit[cur + j]) {
                    if (bridge.find(cur + j) != bridge.end()) {
                        q.push(bridge[cur + j]);
                    } else {
                        q.push(cur + j);
                    }
                    visit[cur + j] = true;
                }
            }
        }
        ans++;
    }

    cout << ans;

    return 0;
}