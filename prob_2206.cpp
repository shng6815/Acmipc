#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[1001];
int visit[1001][1001][2];
queue<pair<pair<int, int>, int>> q;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int N, M;
    string s;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    q.push({{0, 0}, 0});
    visit[0][0][0] = 1;
    int ans = 1;

    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curY, curX, curState;
            curY = q.front().first.first;
            curX = q.front().first.second;
            curState = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nextY, nextX;
                nextY = curY + dir[j][0];
                nextX = curX + dir[j][1];
                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                    if (map[nextY][nextX] != '0' && !curState &&
                        !visit[nextY][nextX][1]) {
                        q.push({{nextY, nextX}, 1});
                        visit[nextY][nextX][1] = 1;
                        continue;
                    }
                    if (map[nextY][nextX] == '0' &&
                        !visit[nextY][nextX][curState]) {
                        q.push({{nextY, nextX}, curState});
                        visit[nextY][nextX][curState] = 1;
                    }
                }
            }
        }
        ans++;
        if (visit[N - 1][M - 1][0] || visit[N - 1][M - 1][1]) {
            cout << ans;
            break;
        }
    }
    if (!visit[N - 1][M - 1][0] && !visit[N - 1][M - 1][1]) {
        cout << -1;
    }
    return 0;
}