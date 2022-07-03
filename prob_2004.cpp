#include <iostream>
#include<algorithm>

using namespace std;

long long cnt;
long long count(long long n, int k) {
   cnt = 0;
   for (long long i = k; i <= n; i *= k) {
      cnt += n / i;
   }
   return cnt;
}
int main() {
   long long n, m;
   long long sum,sum2;
   cin >> n >> m;
   sum = count(n,5);
   sum -= count(m,5);
   sum -= count(n - m,5);

   sum2 = count(n,2);
   sum2 -= count(m,2);
   sum2 -= count(n - m,2);

   cout << min(sum,sum2);
   return 0;
}