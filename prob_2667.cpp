#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
char map[26][26];
bool visit[26][26];
vector<int> res;
int dfs(int y, int x, int n) {
   int sum = 0;
   if (((visit[y][x] == false && map[y][x] == '1') && (y >= 0 && y < n)) &&
       (x >= 0 && x < n)) {
      visit[y][x] = true;
      sum++;
      sum += dfs(y + 1, x, n);
      sum += dfs(y - 1, x, n);
      sum += dfs(y, x + 1, n);
      sum += dfs(y, x - 1, n);
   }
   return sum;
}

int main() {
   int N;
   int cnt = 0;
   cin >> N;
   for (int i = 0; i < N; i++) {
      cin >> map[i];
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (visit[i][j] == false && map[i][j] == '1') {
            cnt++;
            res.push_back(dfs(i, j, N));
         }
      }
   }
   cout << cnt << '\n';
   sort(res.begin(), res.end());
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << '\n';
   }
   return 0;
}