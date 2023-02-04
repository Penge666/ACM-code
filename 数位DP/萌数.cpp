#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 40 , M = 40, mod = 1e9+7 ;
int a[N];
int dp[1009][11][11][3][3][3][3];
int DP(int pos,int pr,int pre,int lead1,int lead2,int limit,int st){
    if(!pos) return st;
    if(!limit&&!lead1&&!lead2&&dp[pos][pr][pre][lead1][lead2][limit][st]!=-1){
        return dp[pos][pr][pre][lead1][lead2][limit][st];
    }
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        int tmp=lead1;
        ans=(ans+DP(pos-1,pre,i,lead1&&(!i),lead2&&tmp,limit&&(i==high),st||(i==pr)*(!lead2)||(i==pre)*(!lead1)))%mod;
    }
    if(!limit&&!lead1&&!lead2)
        dp[pos][pr][pre][lead1][lead2][limit][st]=ans;
    return ans;
}
int slove(string n){
    int len=0;
    for(int i=n.size()-1;i>=0;i--) a[++len]=(int)(n[i]-'0');
    return DP(len,0,0,1,1,1,0);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    string L,R;
    cin>>L>>R;
    int f=0;
    for(int i=1;i<L.size();i++){
        if(L[i]==L[i-1]) f=1;
    }
    for(int i=2;i<L.size();i++){
        if(L[i]==L[i-2]) f=1;
    }
    cout<<(slove(R)-slove(L)+f+mod)%mod;
    return 0;
}
