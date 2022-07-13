#include <algorithm>
#include <iostream>
using namespace std;

int dp[101][1001];

int memory[101];
int cost[101];
int sum;

void solve(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - cost[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }
    solve(N);
    for (int i = 0; i <= sum; i++) {
        if (dp[N][i] >= M) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}