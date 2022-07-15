#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    int M;
    string s;
    bool flag = false;
    int sum = 0;
    int ans = 0;

    cin >> N >> M;
    cin >> s;

    for (int i = 0; i < M - 2; i++) {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            sum++;
            if (sum == N) {
                ans++;
                sum--;
            }
        } else if (s[i] == 'O' && s[i + 1] == 'I') {
            continue;
        } else {
            sum = 0;
        }
    }
    cout << ans;

    return 0;
}