#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    for (int i = 2; i < N; i++) {
        for (int j = 1; j + i <= N; j++) {
            if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1]) {
                dp[j][i + j] = 1;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}