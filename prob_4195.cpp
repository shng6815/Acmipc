#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> m;
unordered_map<string, int> n;

string find(string a) {
   if (m[a] == a)
      return a;
   else
      return m[a] = find(m[a]);
}

void uni(string a, string b) {
   string A = find(a);
   string B = find(b);

   if (A == B) return;

   m[B] = A;
   n[A] += n[B];
}

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;

   for (int i = 0; i < T; i++) {
      int N;
      cin >> N;

      m.clear();
      n.clear();

      for (int j = 0; j < N; j++) {
         string a, b;
         cin >> a >> b;
         if (m.count(a) == 0) {
            m.insert(make_pair(a, a));
            n.insert(make_pair(a, 1));
         }
         if (m.count(b) == 0) {
            m.insert(make_pair(b, b));
            n.insert(make_pair(b, 1));
         }
         uni(a, b);
         cout << n[find(a)] << '\n';
      }
   }

   return 0;
}