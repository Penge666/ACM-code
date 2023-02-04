/*
题意让我们用最少的代价把叶子节点到根节点的距离调成相同

显然，我们调整靠近根节点的树枝，其下叶子节点距离根节点的距离都会增加，所以，调整越靠根节点的树枝调整的代价越少。

为了方便作图，效果直观，在此我们用节点深度类比距离

所以我们可以先找到最深的叶子节点

再从最小的子树开始，把所有子节点调整到同一深度，再调整子树上面的树枝
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f;
struct Node{int v,w;};
vector<Node> g[N];
int ans,n,s,dp[N];//dp[u]:以u为根节点的子树中最长链的长度
int dfs(int u,int fa){
    dp[u]=0;//表示从当前点往下走的最大的长度
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        int d=dfs(v,u)+w;
        dp[u]=max(dp[u],d);
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        ans+=(dp[u]-w-dp[v]);
    }
    return dp[u];
}
signed main(){
    cin>>n>>s;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    dfs(s,0);
    cout<<ans;
    return 0;
}
/*
5 2
1 2 1
1 3 3
2 4 4
2 5 2
*/
