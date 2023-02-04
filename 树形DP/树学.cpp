#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1666666 , inf = 0x3f3f3f3f;
int n,sz[N],dep[N];
int dp[N];//以u为根节点的子树的深度和
vector<int> g[N];
//第一遍dfs，获取dep[],sz[]数组
void dfs1(int u,int fa){
    sz[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
//第二遍dfs，换根后计算以每个结点为根节点的深度和
void dfs2(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dp[v]=(dp[u]-sz[v])+(n-sz[v]);
        dfs2(v,u);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dep[0]=-1;
    dfs1(1,0);//假设以1为根节点
    for(int i=1;i<=n;i++) dp[1]+=dep[i];
    //cout<<dp[1]<<" ";
    dfs2(1,0);
    int ans=inf;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
    cout<<ans;
    return 0;
}
