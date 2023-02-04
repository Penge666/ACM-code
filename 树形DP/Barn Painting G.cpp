/*
���� dp[i][j] ��ʾ��ǰ��i�ڵ㣬��ɫΪj�ķ���������ô�������ڵ��Ѿ��̶��ˣ���ô����
����Ҫ����������ɫ��������Ϊ0.

*/
/*
dp[u,k]:������uΪ���ڵ������,��uȾ��kɫ�ĺϷ�����
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 100090 , mod = 1e9+7 ;
int dp[N][6];
vector<int> g[N];
map<int,int> vis;
void dfs(int u,int fa){
    if(vis[u]){
        dp[u][vis[u]]=1;
    }else{
        dp[u][1]=dp[u][2]=dp[u][3]=1;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        dp[u][1]=(dp[u][1]*(dp[v][2]+dp[v][3])%mod)%mod;
        dp[u][2]=(dp[u][2]*(dp[v][1]+dp[v][3])%mod)%mod;
        dp[u][3]=(dp[u][3]*(dp[v][2]+dp[v][1])%mod)%mod;
    }
}
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        vis[a]=b;
    }
    dfs(1,-1);
    cout<<(dp[1][1]+dp[1][2]+dp[1][3])%mod;
    return 0;
}
