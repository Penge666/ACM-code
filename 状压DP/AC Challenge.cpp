/*
题意
给出一些题目的价值参数a，b。答对这道题的价值为t×a+b，t是答对题目的数量（包括正在答
的这道题）。每道题不是说答就能答的还必须有条件即做完必做题目。问做完所有的题产生的价
值。
题解：枚举所有可能的状态,并从中选择一个物品，看是否这个物品需要的状态是当前枚举状态
去掉这个物品状态的子集,若是,则可以进行转移。
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 21 , M = 1<<21 , inf = 99999999999;
int n,a[N],b[N],tmp[N];
int dp[M];//dp[state]:当状态为state[假设state状态合法]的最大价值
int count(int state){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(state>>i)&1;
    }
    return sum;
}
signed main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        int num=0;
        scanf("%lld",&num);
        for(int j=0;j<num;j++){
            int k;
            scanf("%lld",&k);
            tmp[i]=tmp[i]|(1<<(k-1));
        }
    }
    for(int i=0;i<M;i++) dp[i]=-inf;
    dp[0]=0;
    for(int i=0;i<(1<<n);i++){
        int cnt=count(i)+1;
        for(int j=0;j<n;j++){
            if((1<<j)&i) continue;
            if((tmp[j]&i)!=tmp[j]) continue;
            dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+cnt*a[j]+b[j]);
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++) ans=max(ans,dp[i]);

    printf("%lld",ans);
    return 0;
}
