/*
因为这是一棵树，所以以x为根的子树根节点x所能产生的贡献为size(x)。最后生成的一棵树的
总贡献便为每个点的贡献之和。
考虑如何换根：显然对于每一个节点都可以成为根节点，我们先dfs一遍找出一棵树的贡献（假
设根节点为1）。然后对于与1号连接的所有点进行转移。设f[x]表示以x为根节点所产生的代
价，则对于x所连接的每个点y，有f[y]=f[x]-size(y)+n-size(y) 这个需要画图理解一下。
（因为对于一次换根，x，y以外的点没有对之前的答案产生新的影响，只需要计算x，y这两个
点产生贡献的变化值即可。
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f ;
vector<int> g[N];
int dp[N];//dp[u]:第一个先涂节点u所获得的最大价值
int n,sz[N],num[N];//num[u]:节点u的连通块大小
void dfs1(int u,int fa){
    sz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dfs1(to,u);
        sz[u]+=sz[to];
    }
}
void dfs2(int u,int fa){
    num[u]=1;
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        num[u]+=sz[to];
        dfs2(to,u);
    }
}
void dfs3(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dp[to]=dp[u]-(num[to]-(n-num[to]));
        dfs3(to,u);
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
    dfs1(1,0);
    dfs2(1,0);

    for(int i=1;i<=n;i++) dp[1]+=num[i];
    dfs3(1,0);
    int ans=-inf;
    /*
    for(int i=1;i<=n;i++) cout<<num[i]<<" ";
    cout<<'\n';
    */
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

    cout<<ans;
    return 0;
}
