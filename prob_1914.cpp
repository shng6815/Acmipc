#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void solve(int n, int s, int t, int e) {
    if (n == 1) {
        cout << s << " " << e << '\n';
        return;
    }

    solve(n - 1, s, e, t);
    cout << s << " " << e << '\n';
    solve(n - 1, t, s, e);
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    string ans = to_string(pow(2, N));
    int idx = ans.find('.');
    ans = ans.substr(0, idx);
    ans[ans.length() - 1] -= 1;
    cout << ans.c_str() << '\n';
    if (N <= 20) solve(N, 1, 2, 3);

    return 0;
}