#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int T;
   string s;
   cin >> T;
   for (int i = 0; i < T; i++) {
      stack<char> arr1;
      stack<char> arr2;
      char tmp;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
         if (s[j] == '<') {
            if (arr1.empty()) {
               continue;
            } else {
               arr2.push(arr1.top());
               arr1.pop();
            }
         } else if (s[j] == '>') {
            if (arr2.empty()) {
               continue;
            } else {
               arr1.push(arr2.top());
               arr2.pop();
            }
         } else if (s[j] == '-') {
            if (arr1.empty()) {
               continue;
            } else {
               arr1.pop();
            }
         } else {
            arr1.push(s[j]);
         }
      }
      for (; !arr1.empty();) {
         arr2.push(arr1.top());
         arr1.pop();
      }
      for (; !arr2.empty();) {
         {
            cout << arr2.top();
            arr2.pop();
         }
      }
      cout << "\n";
   }
   return 0;
}