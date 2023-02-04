#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1666666 , inf = 0x3f3f3f3f;
int n,sz[N],dep[N];
int dp[N];//��uΪ���ڵ����������Ⱥ�
vector<int> g[N];
//��һ��dfs����ȡdep[],sz[]����
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
//�ڶ���dfs�������������ÿ�����Ϊ���ڵ����Ⱥ�
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
    dfs1(1,0);//������1Ϊ���ڵ�
    for(int i=1;i<=n;i++) dp[1]+=dep[i];
    //cout<<dp[1]<<" ";
    dfs2(1,0);
    int ans=inf;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
    cout<<ans;
    return 0;
}
