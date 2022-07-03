#include<iostream>

using namespace std;

long long sum[1000001];
long long d[1001] ={0};

int main(){
    long long n,m,arr;
    long long cnt = 0;
    scanf("%lld %lld",&n,&m);
    sum[0] = 0;
    for (int i = 0; i < n; i++){
        scanf("%lld",&arr);
        sum[i+1] = (arr + sum[i])%m;
        d[sum[i+1]%m]++;
    }
    cnt += d[0];
    for (int i = 0; i < m; i++)
    {
        if (d[i]<2)
            continue;
        cnt+=d[i]*(d[i]-1)/2;
    }
    printf("%lld",cnt);
    return 0;
}