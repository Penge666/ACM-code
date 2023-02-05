/*
题意：给你一个数字n和k个区间,S表示所有区间的并的集合,你目前在1,每次可以从集合中选择一个数字向右移动,问有多少种方法从1走到n.
题解:我们从1开始遍历,dp[i]表示走到目前走到i的方案数,再去遍历每一个集合,用dp[i]更新所有[i+l[j],i+r[j]]中的点,而遍历区间我们可以用差分来O(n)的运行出来.

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , mod = 998244353;
int n,k,l[N],r[N];
int dp[N];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>l[i]>>r[i];
    dp[1]=1;dp[2]=-1;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i]+dp[i-1]+mod)%mod;
        for(int j=1;j<=k;j++){
            dp[i+l[j]]+=dp[i];
            dp[i+r[j]+1]-=dp[i];
            dp[i+l[j]]=(dp[i+l[j]]+mod)%mod;
            dp[i+r[j]+1]=(dp[i+r[j]+1]+mod)%mod;
        }
    }
    cout<<dp[n];
    return 0;
}
