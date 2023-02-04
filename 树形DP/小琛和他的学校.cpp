/*
维护一下每个结点的子树结点个数，以及子树中人的个数
那么这条道路被单向通过的次数就为：(sum[v]*(n-siz[v])+(S-sum[v])*siz[v])*w*2

*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666;
struct Node{int v,w,id;};
vector<Node> g[N];
int n,num[N],S;
//****************
int siz[N],ans[N],sum[N];
void dfs(int u,int fa){
    siz[u]=1;
    sum[u]=num[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        int id=g[u][i].id;
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        sum[u]+=sum[v];
        ans[id]=(sum[v]*(n-siz[v])+(S-sum[v])*siz[v])*w*2;
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i],S+=num[i];
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c,i});
        g[b].push_back((Node){a,c,i});
    }
    dfs(1,-1);
    for(int i=1;i<n;i++) cout<<ans[i]<<'\n';
    return 0;
}
