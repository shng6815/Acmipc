#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up right down left
vector<vector<int>> map(50, vector<int>(50, 0));
bool flag;
int cnt = 0;

void find(int y, int x, int n, int m)
{
    int nextY, nextX;
    if ((map[y][x] == 2) || (map[y][x] == 0))
        return;
    else
    {
        flag = true;
        map[y][x] = 2;
        for (int k = 0; k < 4; k++)
        {
            nextY = y + dir[k][0];
            nextX = x + dir[k][1];
            if ((0 > nextY || nextY >= n) || 0 > nextX || nextX >= m)
                continue;
            else
                find(nextY, nextX, n, m);
        }
    }
}

void solve(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            flag = false;
            find(i, j, n, m);
            cnt +=flag;
        }
    }
}
int main()
{
    int T, M, N, K;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        map = vector<vector<int>>(50, vector<int>(50, 0));
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            int tempY, tempX;
            cin >> tempX >> tempY;
            map[tempY][tempX] = 1;
        }
        solve(N, M);
        cout << cnt << endl;
        cnt = 0;
    }
}