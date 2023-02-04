/*
用 dp[i][j] 表示 i 位比 j 小的数的个数，先计算出 F(a)，然后找出比 F(a) 小的 B 以内的数即可。

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
int f[66],res,a[66];
int dp[20][100006];//dp:表示
int DP(int pos,int sum,int limit){
    if(sum<0) return 0;
    if(!pos){
        return sum<=res?1:0;
    }
    if(sum>res) return 0;
    if(!limit&&dp[pos][sum]!=-1){
        return dp[pos][sum];
    }
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,sum-(i*f[pos-1]),limit&&(i==high));
    }
    if(!limit)
        dp[pos][sum]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,res,1);
}
signed main(){

    int cnt=1;
    for(int i=0;i<=20;i++) f[i]=1<<i;
    int T;
    scanf("%lld",&T);
    memset(dp,-1,sizeof(dp));
    while(T--){
        int A,B;
        scanf("%lld%lld",&A,&B);
        res=0;
        int add=1;
        int tmp=A;
        while(tmp){
            res+=(tmp%10)*add;
            add*=2;
            tmp/=10;
        }
        printf("Case #%lld: %lld\n",cnt++,slove(B));
    }
    return 0;
}
