#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    while (T--) {
        int M, N, x, y, i;
        cin >> M >> N >> x >> y;

        for (i = x; i <= lcm(M, N); i += M) {
            int temp = (i % N == 0) ? N : i % N;
            if (temp == y) {
                printf("%d\n", i);
                break;
            }
        }
        if (i > lcm(M, N)) printf("-1\n");
    }

    return 0;
}