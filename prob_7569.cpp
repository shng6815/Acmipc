#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class pos {
   public:
    int z, y, x;
    pos(int Z, int Y, int X) {
        z = Z;
        y = Y;
        x = X;
    }
};

int M, N, H;
int map[100][100][100];
bool visit[100][100][100];
queue<pos> q;
int ans;
pos dir[6] = {{0, 0, 1},  {0, 1, 0}, {0, 0, -1},
              {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

bool check(pos p) {
    if (p.y < N && p.y >= 0 && p.x >= 0 && p.x < M && p.z >= 0 && p.z < H &&
        map[p.z][p.y][p.x] == 0 && !visit[p.z][p.y][p.x]) {
        return true;
    }
    return false;
}

void bfs() {
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 6; j++) {
                pos cur = {q.front().z + dir[j].z, q.front().y + dir[j].y,
                           q.front().x + dir[j].x};
                if (check(cur)) {
                    q.push(cur);
                    visit[cur.z][cur.y][cur.x] = true;
                }
            }
            q.pop();
        }
        ans++;
    }
}

int main() {
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[k][i][j];
                if (map[k][i][j] == 1) {
                    q.push({k, i, j});
                    visit[k][i][j] = true;
                }
                if (map[k][i][j] == -1) {
                    visit[k][i][j] = true;
                }
            }
        }
    }

    bfs();
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visit[k][i][j] == false) ans = 0;
            }
        }
    }
    cout << ans - 1;
    return 0;
}