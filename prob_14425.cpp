#include <iostream>
#include <map>

using namespace std;
map<string, bool> m;

int main(void) {
   int N, M;
   int cnt = 0;
   cin >> N >> M;
   string temp;
   for (int i = 0; i < N; i++) {
      cin >> temp;
      m.insert(pair<string, bool>(temp, true));
   }

   for (int i = 0; i < M; i++) {
      cin >> temp;
      if (m[temp] == true) cnt++;
   }
   cout << cnt;
}