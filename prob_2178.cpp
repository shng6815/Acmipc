#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string maze[101];
int visit[101][101];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<pair<int, int>> q;
int ans;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }
    visit[0][0] = 1;
    q.push({0, 0});
    ans = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curY, curX;
            curY = q.front().first;
            curX = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nextY, nextX;
                nextY = curY + dir[j][0];
                nextX = curX + dir[j][1];
                if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N &&
                    !visit[nextY][nextX] && maze[nextY][nextX] == '1') {
                    visit[nextY][nextX] = 1;
                    q.push({nextY, nextX});
                }
            }
        }
        ans++;
        if (visit[N - 1][M - 1]) {
            break;
        }
    }

    cout << ans;

    return 0;
}