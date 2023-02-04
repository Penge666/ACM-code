#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1000009;
int sum,X,n;
int dp[51][11][11][600];
int DP(int pos,int pre1,int pre2,int add){
    //
    if(!pos){
    //    cout<<pos<<" "<<pre1<<" "<<pre2<<" "<<add<<'\n';
        return add==sum?1:0;
    }
    if(dp[pos][pre1][pre2][add]!=-1)
        return dp[pos][pre1][pre2][add];
    int ans=0;
    for(int i=0;i<=9;i++){
        if(((n-pos>=2)&&(pre1*100+pre2*10+i)%X!=0)||(add+i>sum)){
            continue;
        }
        else{
            ans=(ans+DP(pos-1,pre2,i,add+i))%mod;
        }
    }
    dp[pos][pre1][pre2][add]=ans;
    return ans;
}
signed main(){
    cin>>n>>sum>>X;
    memset(dp,-1,sizeof(dp));
    cout<<DP(n,0,0,0)%mod;
    return 0;
}
