#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100001];
int visited[100001] = {0};

void dfs(int start) {
   visited[start] = 1;
   printf("%d ",start);
   for (int i = 0; i < graph[start].size(); i++) {
      int next = graph[start][i];
      if (visited[next] == 0) {
         dfs(next);
      }
   }
}

void bfs(int r) {
   queue<int> q;
   q.push(r);
   visited[r] = 1;
   printf("%d ",r);
   while (!q.empty()) {
      int inq = q.front();
      q.pop();
      for (int i = 0; i < graph[inq].size(); i++) {
         int temp = graph[inq][i];
         if (!visited[temp]) {
            printf("%d ",temp);
            q.push(temp);
            visited[temp] = 1;
         }
      }
   }
}
int main() {
   int n, m, r;
   scanf("%d %d %d", &n, &m, &r);
   for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   for (int i = 1; i <= n; i++) {
      sort(graph[i].begin(), graph[i].end());
   }
   dfs(r);
   printf("\n");
   for (int i = 0; i < 10001; i++) {
      visited[i] = 0;
   }
   bfs(r);

   return 0;
}