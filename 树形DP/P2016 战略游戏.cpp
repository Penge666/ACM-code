#include<bits/stdc++.h>

using namespace std;
const int N = 66666;
vector<int> g[N];
int n;
int dp[N][6];
void dfs(int u,int fa){
    dp[u][1]=1,dp[u][0]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int u,m;
        cin>>u>>m;
        for(int j=0;j<m;j++){
            int v;
            cin>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(0,-1);
    cout<<min(dp[0][0],dp[0][1]);
    return 0;
}
