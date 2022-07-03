#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<int, vector<int>, less<int> >pq;
pair<int, int> fuel[10000];

int main(void) {
    int N, L, P, cnt=0;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>fuel[i].first>>fuel[i].second;
    }
    sort(fuel, fuel + N);

    cin>>L>>P;
    int idx = 0;

    while (L > P) {
        while (fuel[idx].first <= P && idx < N)
            pq.push(fuel[idx++].second);
        if (!pq.empty()) {
            P += pq.top();
            pq.pop();
            cnt++;
        }
        else if (idx == N || fuel[idx].first > P) {
            cnt = -1;
            break;
        }
    }
    cout<<cnt;

    return 0;
}