#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        priority_queue<long long> maxPq;
        priority_queue<long long> minPq;
        map<long long, int> m;
        for (int i = 0; i < k; i++) {
            char c;
            long long n;
            cin >> c >> n;
            if (c == 'I') {
                maxPq.push(n);
                minPq.push(-n);
                m[n]++;
            } else {
                if (!m.empty()) {
                    if (n == 1) {
                        while (!maxPq.empty() && m[maxPq.top()] == 0) {
                            maxPq.pop();
                        }
                        if (!maxPq.empty()) {
                            m[maxPq.top()]--;
                            maxPq.pop();
                        }
                    } else {
                        while (!minPq.empty() && m[-minPq.top()] == 0) {
                            minPq.pop();
                        }
                        if (!minPq.empty()) {
                            m[-minPq.top()]--;
                            minPq.pop();
                        }
                    }
                }
            }
        }
        while (!maxPq.empty() && m[maxPq.top()] == 0) {
            maxPq.pop();
        }
        while (!minPq.empty() && m[-minPq.top()] == 0) {
            minPq.pop();
        }
        if (maxPq.empty() || minPq.empty()) {
            cout << "EMPTY\n";
        } else
            cout << maxPq.top() << " " << -minPq.top() << '\n';
    }

    return 0;
}