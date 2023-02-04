/*
(树形DP+状态机) O(n)
首先这道题的题意是：给定一棵树，要在一些节点上放置守卫，每个守卫可以看护当前节点
以及与此节点连通的节点，在不同节点放置守卫的代价不同，如何选取节点使代价最小，这
是个典型的树形DP问题，显然每个节点有放置守卫和不放置守卫两种，但是从计算的过程
看，不放置守卫的状态由两种，一种是有其父节点上的守卫看护，一种是由其子节点的守卫
看护，因此可将每个节点的看护情况分为三种：

该节点由父节点处放置的守卫看护
该节点由子节点处放置的守护看护
该节点由在该节点放置的守卫看护
下面考虑状态转移的过程，建立数组f[i][3]，其中

f[i][0]表示第i个节点由父节点处放置的守卫看护下的最小代价
f[i][1]表示第i个节点由子节点处放置的守卫看护下的最小代价
f[i][2]表示第i个节点由在该节点放置的守卫看护下的最小代价
那么可以写出转移关系：

f[i][0] += min(f[j][1], f[j][2]);
f[i][1] = min(f[i][1], sum - min(f[j][1], f[j][2]) + f[j][2]);
f[i][2] += min(min(f[j][0], f[j][1]), f[j][2]);
其中j为i的子节点，sum为所有子节点j的min(f[j][1],f[j][2])的和，1和3的意义很明显，
2的意义代表，如果第i个节点由子节点守卫，那么所有子节点都不能由父节点守卫，并且每
个子节点都得到了守卫，且至少有一个子节点处放置了守卫

至此，算法思路就很清晰了，下面就用常规求解过程来写代码
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 3333, inf = 0x3f3f3f3f;
int n,cost[N];
vector<int> g[N];
int dp[N][3],pre[N];
/*
f[i][0]表示第i个节点由父节点处放置的守卫看护下的最小代价
f[i][1]表示第i个节点由子节点处放置的守卫看护下的最小代价
f[i][2]表示第i个节点由在该节点放置的守卫看护下的最小代价
*/
void dfs(int u){
    dp[u][2]=cost[u];
    int sum=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        dp[u][0]=dp[u][0]+min(dp[v][1],dp[v][2]);
        dp[u][2]=dp[u][2]+min(dp[v][1],min(dp[v][2],dp[v][0]));
        sum+=min(dp[v][1],dp[v][2]);
    }
    dp[u][1]=inf;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dp[u][1]=min(dp[u][1],sum-min(dp[v][1],dp[v][2])+dp[v][2]);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,w,m,v;
        cin>>u>>w>>m;
        cost[u]=w;
        for(int j=0;j<m;j++){
            cin>>v;
            g[u].push_back(v);
            pre[v]=1;
        }
    }
    int rt=1;
    while(pre[rt]) rt++;
    dfs(rt);
    cout<<min(dp[rt][2],dp[rt][1]);
    return 0;
}
