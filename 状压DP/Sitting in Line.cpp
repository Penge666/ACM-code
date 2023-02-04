/*
题意: 给定n个数, 让你选择一个序列, 使得这个序列中相邻的两个数乘积之和最大;

dp[i][j]表示在i状态的情况下最后一个添加的是j位置的元素的最大值.

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 17 , M = 1<<16  ,  inf = 0x3f3f3f3f;
int dp[M][N];//dp[s,i]:在状态s下,并以i结尾的最大值 - MAX
//dp[s|(1<<j)][j]=MAX(dp[s][i]+arr[i]*arr[j],dp[s|(1<<j)][j])
int a[N],b[N],n,num[M+10];
int count(int state){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(state>>i)&1;
    }
    return sum;
}
signed main(){

//    for(int i=0;i<10;i++) cout<<num[i]<<" ";
    int T;
    scanf("%lld",&T);
    int cnt=1;
    while(T--){
        memset(dp,-0x3f,sizeof(dp));
        scanf("%lld",&n);
        for(int i=0;i<M;i++) num[i]=count(i);
        for(int i=0;i<n;i++) scanf("%lld%lld",&a[i],&b[i]);
        for(int i=0;i<n;i++){
            if(b[i]==0||b[i]==-1)
                dp[1<<i][i]=0;
        }
        for(int s=0;s<(1<<n);s++){
            for(int i=0;i<n;i++){
                if(s&(1<<i)){
                    for(int j=0;j<n;j++){
                        if(j==i) continue;
                        if(dp[s][i]==-inf) continue;
                        if(!(s&(1<<j))){
                            if(b[j]==-1||num[s]==b[j]){
                                dp[s|(1<<j)][j]=max(dp[s|(1<<j)][j],dp[s][i]+a[i]*a[j]);
                            }
                        }
                    }
                }
            }
        }
        int  ans=-inf;
        for(int i=0;i<n;i++) ans=max(ans,dp[(1<<n)-1][i]);
        printf("Case #%lld:\n",cnt++);
        printf("%lld\n",ans);
    }
    return 0;
}
