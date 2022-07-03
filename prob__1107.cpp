#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int ans = 1000001;
bool cheak = true;
vector<char> v(10, 0);
void solve()
{
    int temp, temp1, ans2 = abs(N - 100);
    for (int i = 0; i < 1000001; i++)
    {
        temp1 = i;
        if (temp1 == 0)
        {
            if (v[0] == 1)
                continue;
            else
            {
                temp = to_string(i).size();
                temp += abs(temp1 - N);
                ans = min(ans, temp);
                continue;
            }
        }
        while (temp1)
        {
            if (v[temp1 % 10] == 1)
            {
                cheak = false;
                break;
            }
            temp1 /= 10;
        }
        if (!cheak)
        {
            cheak = true;
            continue;
        }
        temp = to_string(i).length();
        temp += abs(i - N);
        ans = min(ans, temp);
    }
    cout << min(ans, ans2);
}
int main()
{
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        v[temp] = 1;
    }
    solve();
}