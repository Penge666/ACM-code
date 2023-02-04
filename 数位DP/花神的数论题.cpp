//将N进行二进制拆分，从而得到DP上限，进行数位DP

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66 , mod = 10000007;
int a[N];
int dp[N][N][2];
int DP(int pos,int count,int limit){
    if(!pos) return max(count,1ll);
    if(!limit&&dp[pos][count][limit]!=-1)
        return     dp[pos][count][limit];
    int high=limit?a[pos]:1;
    int ans=1;
    for(int i=0;i<=high;i++){
        ans=(ans*DP(pos-1,count+(i==1?1:0),limit&&(i==high))%mod)%mod;
    }
    if(!limit)
        dp[pos][count][limit]=ans;
    return ans;
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int len=0;
    while(n){
        a[++len]=n%2;
        n=n/2;
    }
    cout<<DP(len,0,1)%mod;
    return 0;
}
