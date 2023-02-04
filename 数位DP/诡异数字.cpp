/*

注意：
1.【l,r】中L进行特判
2.取模
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66 , mod = 20020219;
int vis[N];
int a[N];
int dp[22][11][30][2];
int DP(int pos,int pre,int sum,int limit){
    if(!pos) return 1;
    if(!limit&&dp[pos][pre][sum][limit]!=-1){
        return dp[pos][pre][sum][limit];
    }
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        if(i==pre){
            if(sum+1>vis[i]){
                continue;
            }else{
                ans=(ans+DP(pos-1,i,sum+1,limit&&(i==high)))%mod;
            }
        }else{
            ans=(ans+DP(pos-1,i,1,limit&&(i==high)))%mod;
        }
    }
    if(!limit) dp[pos][pre][sum][limit]=ans;
    return ans;
}
int slove(int n){
    if(n==-1) return 0;
    memset(dp,-1,sizeof(dp));
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,0,0,1);
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<=11;i++) vis[i]=1e18+10;
        int L,R,n;
        cin>>L>>R>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            vis[x]=min(vis[x],y);
        }
        cout<<(slove(R)-slove(L-1)+mod)%mod<<'\n';
    }
    return 0;
}
