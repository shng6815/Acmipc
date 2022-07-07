#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501];
bool visit[501][501];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int M, int N, int y, int x) {
    if (y == M - 1 && x == N - 1) {
        return 1;
    }
    if (visit[y][x]) return dp[y][x];
    visit[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if (ny < M && ny >= 0 && nx < N && nx >= 0) {
            if (map[y][x] > map[ny][nx]) {
                dp[y][x] += dfs(M, N, ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    cout << dfs(M, N, 0, 0);
    return 0;
}