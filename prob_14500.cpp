#include <iostream>

using namespace std;

int tetro[4][4][2] = {{{0, 0}, {0, -1}, {0, 1}, {-1, 0}},
                      {{0, 0}, {-1, 0}, {1, 0}, {0, 1}},
                      {{0, 0}, {0, -1}, {0, 1}, {1, 0}},
                      {{0, 0}, {-1, 0}, {1, 0}, {0, -1}}};
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int map[501][501];
int visit[501][501];
int N, M;

int dfs(int y, int x, int cnt) {
    if (cnt == 3) {
        return map[y][x];
    }

    visit[y][x] = 1;
    int max = 0;
    for (int i = 0; i < 4; i++) {
        int nextY, nextX;
        nextY = y + dir[i][0];
        nextX = x + dir[i][1];
        if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M &&
            !visit[nextY][nextX]) {
            int temp = dfs(nextY, nextX, cnt + 1);
            max = max > temp ? max : temp;
        }
    }
    visit[y][x] = 0;
    return max + map[y][x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp = dfs(i, j, 0);

            max = max > temp ? max : temp;
            for (int k = 0; k < 4; k++) {
                int sum = 0;
                for (int l = 0; l < 4; l++) {
                    int nextY, nextX;
                    nextY = i + tetro[k][l][0];
                    nextX = j + tetro[k][l][1];
                    if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                        sum += map[nextY][nextX];
                    } else
                        break;
                }
                max = max > sum ? max : sum;
            }
        }
    }
    cout << max;

    return 0;
}