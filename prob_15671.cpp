#include <iostream>
using namespace std;

char map[6][6];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
void reset()
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            map[i][j] = '.';
}

void draw(int y, int x, char c)
{
    int res = 0;
    int tempY, tempX, cnt;
    while (res < 8)
    {
        tempY = y + dir[res][0];
        tempX = x + dir[res][1];
        cnt = 1;
        while ((0 <= tempY && tempY < 6) && (0 <= tempX && tempX < 6))
        {
            if (map[tempY][tempX] == '+')
                break;
            if (map[tempY][tempX] == c)
            {
                if (cnt == 1)
                    break;
                for (int i = 1; i <= cnt; i++)
                {
                    tempY = tempY - dir[res][0];
                    tempX = tempX - dir[res][1];
                    map[tempY][tempX] = c;
                }
                break;
            }
            cnt++;
            tempY = tempY + dir[res][0];
            tempX = tempX + dir[res][1];
        }
        res++;
    }
}

void push(int j, int y, int x)
{
    if (j % 2 == 0)
        draw(y, x, 'B');
    else
        draw(y, x, 'W');
}

int main()
{
    int n, y, x, cntY, cntX;

    cntX = cntY = 0;
    reset();
    cin >> n;
    map[2][2] = map[3][3] = 'W';
    map[2][3] = map[3][2] = 'B';
    for (int l = 0; l < n; l++)
    {
        cin >> y >> x;
        push(l, y - 1, x - 1);
    }
    for (int j = 0; j < 6; j++)
    {
        for (int k = 0; k < 6; k++)
        {
            if (map[j][k] == 'B')
                cntX++;
            else if (map[j][k] == 'W')
                cntY++;
        }
    }
    for (int j = 0; j < 6; j++)
    {
        for (int k = 0; k < 6; k++)
            cout << map[j][k];
        cout << "\n";
    }
    cout << ((cntX>cntY) ? "Black" : "White") << endl;
    return 0;
}