/*
题意：给定一棵NN个节点的无根树，点有点权，点权有正有负，求这棵树的联通块的最大权值之和是多少。
dp[p]表示以p为根且包含u的最大权联通块
转移方程：dp[u]+=max(dp[v],0)

*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f ;
vector<int> g[N];
int n,a[N],dp[N];
//dp[u]:以u为根节点的子树修剪之后最大值
void dfs(int u,int fa){
    dp[u]=a[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        dp[u]+=max(0ll,dp[v]);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
