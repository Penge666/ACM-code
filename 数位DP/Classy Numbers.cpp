#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20 ;
int a[N];
int dp[N][N][N];
int DP(int pos,int sum,int limit){
    if(!pos) return 1;
    if(!limit&&dp[pos][sum][limit]!=-1)
        return dp[pos][sum][limit];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        if(sum==3&&i!=0) continue;
        ans+=DP(pos-1,sum+(i!=0),limit&&(i==high));
    }
    if(!limit)
        dp[pos][sum][limit]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,0,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int T;
    cin>>T;
    while(T--){
        int L,R;
        cin>>L>>R;
        cout<<slove(R)-slove(L-1)<<'\n';
    }
    return 0;
}
