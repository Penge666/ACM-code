#include<bits/stdc++.h>

using namespace std;
//#define int long long
const int N = 666666;
int n,pre[N];
vector<int> g[N];
double a[N],dp[N][2];
//dp[u,0/1]:以u为根节点的子树中，u到与不到的情况
void dfs(int u){
    dp[u][1]=a[u],dp[u][0]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        dp[u][1]+=max(dp[v][1]-a[v]/2.0,dp[v][0]);
        dp[u][0]+=max(dp[v][1],dp[v][0]);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        g[a].push_back(b);
        pre[b]=1;
    }
    int rt=1;
    while(pre[rt]) rt++;
    dfs(rt);
    printf("%.1lf",max(dp[rt][0],dp[rt][1]));
    return 0;
}
