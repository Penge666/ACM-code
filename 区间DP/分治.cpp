// 直接枚举攻打点，分成两个区间，然后区间dp一下。

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666
int dp[N][N];
/*
dp(l,r):消灭区间[l,r]上的敌人所花费的最小金额
MIN
dp[l,r]=SUM[l,r] = = dp[l][k]+dp[k+1][r]+(len-1)*cost[k]
*/
int T,n,cost[N];

signed main(){
    cin>>T;
    while(T--){
        memset(dp,0x3f,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++) cin>>cost[i];
        for(int i=0;i<=n;i++) dp[i][i]=0;
        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                for(int k=l;k<=r;k++){
                    dp[l][r]=min(dp[l][r],dp[l][max(k-1,l)]+dp[min(k+1,r)][r]+cost[k]*(len-1));
                }
            }
        }
        cout<<dp[1][n]<<'\n';
    }
    return 0;
}
