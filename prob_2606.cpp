#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int map[101][101];
int virus[101];

void dfs(int i,int t){
    for (int j = 1; j <= t; j++)
    {
        if(map[i][j] == 1){
            map[i][j] = 0;
            map[j][i] = 0;
            virus[j] = 1;
            dfs(j,t);
        }
    }
}

int main(){
    int t,n;
    int temp1,temp2;
    int cnt = 0;
    cin>>t>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>temp1>>temp2;
        map[temp1][temp2] = 1;
        map[temp2][temp1] = 1;
    }

    dfs(1,t);
    virus[1]=0;
    for (int i = 1; i <= t; i++)
        cnt += virus[i];
    cout<<cnt;
    return 0;
}