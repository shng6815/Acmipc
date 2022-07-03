#include <iostream>
#include <string>

using namespace std;

int arr[26][200001];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   string S;
   int q, start, end;
   char a;

   cin >> S;

   for (int j = 1; j <= S.size(); j++) {
      arr[S[j - 1] - 'a'][j]++;
      for (int i = 0; i < 26; i++) {
         arr[i][j] += arr[i][j - 1];
      }
   }
   cin >> q;
   for (int i = 0; i < q; i++) {
      cin >> a >> start >> end;
      cout << arr[(int)a - int('a')][end + 1] - arr[(int)a - int('a')][start]
           << '\n';
   }
}
