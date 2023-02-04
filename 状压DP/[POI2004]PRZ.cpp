#include<bits/stdc++.h>

using namespace std;
#define int long long
const int  N =  1<<18 ;
int n,m,t[66],w[66];
int dp[N];//dp[i]:状态i过桥所需的最小时间
int dt[N]; //dp[i]:状态i过桥所需的时间
int dw[N]; //dp[i]:状态i过桥总重量
signed main(){
    cin>>m>>n;
    for(int i=0;i<n;i++) cin>>t[i]>>w[i];
    for(int i=0;i<(1<<n);i++){
        int sum_wi=0,maxn_ti=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum_wi+=w[j];
                maxn_ti=max(maxn_ti,t[j]);
            }
        }
        dt[i]=maxn_ti,dw[i]=sum_wi;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<(1<<n);i++){
        for(int j=i;j!=0;j=(j-1)&i){
            if(dw[j]<=m)
                dp[i]=min(dp[i],dp[i^j]+dt[j]);
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}
