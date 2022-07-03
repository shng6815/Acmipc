#include <iostream>
#include <queue>
using namespace std;

int main() {
   queue<int> q;
   int N, K;
   int tail, max = -10000000;
   int sum = 0;
   cin >> N >> K;
   for (int i = 0; i < N; i++) {
      int temp;
      cin >> temp;
      sum += temp;
      q.push(temp);
      if (i >= K-1) {
         max = max > sum ? max : sum;
         sum -= q.front();
         q.pop();
      }
   }
   cout << max;
}