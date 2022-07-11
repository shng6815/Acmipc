#include <cmath>
#include <iostream>
using namespace std;

int dp[31][40001];
int w[31];

void solve(int cnt, int W, int N) {
    if (cnt > N || dp[cnt][W]) {
        return;
    }
    dp[cnt][W] = 1;
    solve(cnt + 1, W + w[cnt], N);
    solve(cnt + 1, W, N);
    solve(cnt + 1, abs(W - w[cnt]), N);
}

int main() {
    int N, G;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    solve(0, 0, N);

    cin >> G;
    for (int i = 0; i < G; i++) {
        int temp;
        cin >> temp;
        cout << (dp[N][temp] ? 'Y' : 'N') << ' ';
    }

    return 0;
}