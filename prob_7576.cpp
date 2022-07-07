#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int M, N;
int map[1000][1000];
bool visit[1000][1000];
queue<pair<int, int>> q;
int ans;
pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool check(pair<int, int> p) {
    if (map[p.first][p.second] == 0 && !visit[p.first][p.second] &&
        p.first < N && p.first >= 0 && p.second >= 0 && p.second < M) {
        return true;
    }
    return false;
}

void bfs() {
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                pair<int, int> cur = {q.front().first + dir[j].first,
                                      q.front().second + dir[j].second};
                if (check(cur)) {
                    q.push(cur);
                    visit[cur.first][cur.second] = true;
                }
            }
            q.pop();
        }
        ans++;
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
                visit[i][j] = true;
            }
            if (map[i][j] == -1) {
                visit[i][j] = true;
            }
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == false) ans = 0;
        }
    }

    cout << ans - 1;
    return 0;
}