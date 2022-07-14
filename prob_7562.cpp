#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                 {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main() {
    int T, I, M;
    cin >> T;

    while (T--) {
        queue<pair<int, int>> q;
        int visit[301][301] = {0};
        cin >> I;
        int tempY, tempX, tarY, tarX;
        cin >> tempY >> tempX;
        cin >> tarY >> tarX;
        visit[tempY][tempX] = 1;
        q.push({tempY, tempX});
        int ans = 0;

        while (!q.empty()) {
            if (visit[tarY][tarX]) {
                break;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curY, curX;
                curY = q.front().first;
                curX = q.front().second;
                q.pop();
                for (int j = 0; j < 8; j++) {
                    int nextY, nextX;
                    nextY = curY + dir[j][0];
                    nextX = curX + dir[j][1];
                    if (nextX >= 0 && nextX < I && nextY >= 0 && nextY < I &&
                        !visit[nextY][nextX]) {
                        visit[nextY][nextX] = 1;
                        q.push({nextY, nextX});
                    }
                }
            }
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}