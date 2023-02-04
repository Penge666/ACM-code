#include<bits/stdc++.h>

using namespace std;
const int N = 10010 ,inf = 0x3f3f3f3f;
struct Node{
    int v,w;
};
int n;
vector<Node> g[N];
int d1[N],d2[N],p[N],up[N];
int dfs_down(int u,int fa){
    d1[u]=d2[u]=-inf;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        int d=dfs_down(v,u)+w;
        if(d>=d1[u]){
            d2[u]=d1[u];
            d1[u]=d;
            p[u]=v;
        }else if(d>d2[u]) d2[u]=d;
    }
    if(d1[u]==-inf){
        d1[u]=d2[u]=0;
    }
    return d1[u];
}
void dfs_up(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        if(p[u]==v) up[v]=max(up[u],d2[u])+w;
        else up[v]=max(up[u],d1[u])+w;
        dfs_up(v,u);
    }
}
int main(){
    cin>>n;
    int a,b,c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    dfs_down(1,-1);
    dfs_up(1,-1);
    int res=d1[1];
    for(int i=2;i<=n;i++) res=min(res,max(d1[i],up[i]));
    cout<<res;
    return 0;
}
