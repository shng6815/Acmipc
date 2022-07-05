#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[100001];
int ans;

queue<pair<int, int>> q;

void bfs(int N, int M) {
   while (!q.empty()) {
      int data = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (data == M) {
         ans = depth;
         break;
      }

      if (data - 1 <= 100000 && data - 1 >= 0 && !visit[data - 1]) {
         visit[data - 1] = true;
         q.push({data - 1, depth + 1});
      }
      if (data + 1 <= 100000 && data + 1 >= 0 && !visit[data + 1]) {
         visit[data + 1] = true;
         q.push({data + 1, depth + 1});
      }
      if (data * 2 <= 100000 && data * 2 >= 0 && !visit[data * 2]) {
         visit[data * 2] = true;
         q.push({data * 2, depth + 1});
      }
   }
}

int main() {
   int N, M;
   cin >> N >> M;
   q.push({N, 0});
   visit[N] = true;
   bfs(N, M);

   cout << ans;

   return 0;
}