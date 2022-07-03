#include <iostream>

using namespace std;

int dp[501][501];
int sum[501];
int arr[501];
int main() {
   int T;
   cin >> T;
   while (T--) {
      int K;
      cin >> K;
      for (int i = 1; i <= K; i++) {
         cin >> arr[i];
         sum[i] = arr[i] + sum[i - 1];
      }
      for (int i = 1; i <= K; i++) {
         for (int j = 1; j <= K - i; j++) {
            dp[j][i + j] = 1000000000;
            for (int k = j; k < i + j; k++) {
               dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] +
                                                    sum[i + j] - sum[j - 1]);
            }
         }
      }
      cout << dp[1][K] << '\n';
   }
   return 0;
}