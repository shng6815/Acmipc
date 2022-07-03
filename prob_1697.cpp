#include <iostream>
using namespace std;

bool visit[100001];
int Min = 100001;
void bfs(int N, int M, int cnt) {
   cout<<N<<endl;
   if (visit[N] || N > 100000 || N < 0) {
      return;
   }
   if (N == M) {
      Min = Min > cnt ? cnt : Min;
      return;
   }

   visit[N] = true;
   bfs(N - 1, M, cnt + 1);
   bfs(N + 1, M, cnt + 1);
   bfs(N * 2, M, cnt + 1);
   visit[N] = false;
}

int main() {
   int N, M;
   cin >> N >> M;

   bfs(N, M, 0);

   cout << Min;

   return 0;
}