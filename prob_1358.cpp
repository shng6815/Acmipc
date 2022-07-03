#include <math.h>

#include <iostream>

using namespace std;

int main() {
   double W, H, X, Y, P;
   cin >> W >> H >> X >> Y >> P;
   int cnt = 0;
   for (int i = 0; i < P; i++) {
      double y, x;
      cin >> x >> y;
      double temp1 =
          sqrt((x - X) * (x - X) + (y - (Y + H / 2)) * (y - (Y + H / 2)));
      double temp2 = sqrt((x - (X + W)) * (x - (X + W)) +
                          (y - (Y + H / 2)) * (y - (Y + H / 2)));
      if ((((y <= Y + H && y >= Y) && (x <= X + W && x >= X)) ||
           temp1 <= H / 2.0f) ||
          temp2 <= H / 2.0f)
         cnt++;
   }
   cout << cnt;
   return 0;
}