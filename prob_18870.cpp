#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int T,temp;
    vector<int> v,v2;
    cin>>T;
    for(int i = 0; i<T;i++){
        cin>>temp;
        v.push_back(temp);
        v2.push_back(temp);
    }
    
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i = 0; i < T; i++) {
        cout<<lower_bound(v.begin(), v.end(), v2[i]) - v.begin()<<" ";
    }
}