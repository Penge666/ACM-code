#include<bits/stdc++.h>

using namespace std;
const int N = 6666;
int n,w[N];
vector<int> g[N];
int hasfather[N];
int dp[N][2];
void dfs(int u){
    dp[u][1]=w[u];
    dp[u][0]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[b].push_back(a);
        hasfather[a]=1;
    }
    int root=1;
    while(hasfather[root]) root++;
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);
    return 0;
}
