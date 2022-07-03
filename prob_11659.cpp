#include<iostream>

using namespace std;

int arr[100000];
int sum[100001];

int main(){
    int m,n,a,b;

    cin>>n>>m;
    sum[0] = 0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        sum[i+1] = arr[i] + sum[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        cout<<sum[b] - sum[a-1]<<endl;
    }
    
    return 0;
}