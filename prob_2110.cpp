#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)
 
using namespace std;
 
int main(){
    vector<int> house;
    int N, C;
    cin >> N >> C;
 
    for (int n_idx = 0; n_idx < N; n_idx++) {
        int sub;
        scanf("%d", &sub);
        house.push_back(sub);
    }
    sort(house.begin(), house.end());
    int left = house.front(),right = house.back();
 
    while (left <= right) {
        int mid = (left + right) / 2;
        int preIdx = 0;
        int set_num = 1;
        for (int n_idx = 1; n_idx < N; n_idx++) {
             if (house.at(n_idx) - house.at(preIdx) >= mid) {
                preIdx = n_idx;
                set_num++; 
            } 
        }
        if (set_num >= C)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right;
 
    return 0; 
}
