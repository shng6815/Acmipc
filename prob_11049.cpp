#include <algorithm>
#include <iostream>
using namespace std;

int mat[501][2];
int dp[501][501];

int main() {
   int N;
   cin >> N;
   for (int i = 1; i <= N; i++) {
      cin >> mat[i][0] >> mat[i][1];
   }

   for (int i = 1; i < N; i++) {
      for (int j = 1; j + i <= N; j++) {
         dp[j][i + j] = 1000000000;
         for (int k = j; k <= i + j; k++) {
            dp[j][j + i] =
                min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] +
                                      mat[j][0] * mat[k][1] * mat[i + j][1]);
         }
      }
   }

   cout << dp[1][N];
   getchar();
   return 0;
}