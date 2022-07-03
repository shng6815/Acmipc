#include <iostream>

using namespace std;
int map[1025][1025];

int main() {
   ios_base ::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int N, M;
   int y1, x1, y2, x2;
   cin >> N >> M;

   for (int i = 0; i < N; i++) {
      for (int j = 1; j <= N; j++) {
         cin >> map[i][j];
         map[i][j] += map[i][j - 1];
      }
   }

   for (int i = 0; i < M; i++) {
      int sum = 0;
      cin >> y1 >> x1 >> y2 >> x2;
      for (int i = 0; i <= y2 - y1; i++) {
         sum += map[y1 + i - 1][x2] - map[y1 + i - 1][x1 - 1];
      }
      cout << sum << '\n';
   }
}