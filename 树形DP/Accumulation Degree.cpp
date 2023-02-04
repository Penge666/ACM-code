#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+10 , inf = 0x3f3f3f3f;
struct Node{int v,w;};
vector<Node> g[N];
int n;
int flow[N];//以u为根节点的子树的最大流量
int dp[N];  //以u为根节点的子树，到所有叶子结点路径上流量和
int dfs1(int u,int fa){
    int sum=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        if(g[v].size()==1) sum+=w;
        else{
            dfs1(v,u);
            sum+=min(flow[v],w);
        }
    }
    return flow[u]=sum;
}
void dfs2(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        dp[v]=flow[v]+min(w,dp[u]-min(w,flow[v]));
        dfs2(v,u);
    }
}
void init(){
    memset(dp,0,sizeof(dp));
    memset(flow,0,sizeof(flow));
    for(int i=0;i<N;i++) g[i].clear();
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        init();
        cin>>n;
        for(int i=1;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back((Node){b,c});
            g[b].push_back((Node){a,c});
        }
        dfs1(1,0);
        dp[1]=flow[1];
        dfs2(1,0);
        int ans=-inf;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout<<ans<<'\n';
    }
    return 0;
}
