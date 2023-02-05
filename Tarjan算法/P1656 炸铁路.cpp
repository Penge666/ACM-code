/*

裸的割边模板，虽然不需要判断重边但是还是加上比较好。

判断是否是树枝边的反向边的时候只需要判断vis[i^1]是否等于1就行了，因为是这样判断的，所以在建边的时候cnt必须从1开始，因为0^1=0,并不会得到1这条反向边。


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int head[N],cnt1=1;
struct edge{
    int u;
    int to;
    int next;
}e[N*2];
void addedge(int u,int v){
    e[++cnt1].to=v;
    e[cnt1].next=head[u];
    head[u]=cnt1;
}

vector<int> v[N];
int low[N],dfn[N],cnt;
int n,m;
int vis[N];
struct str{
    int u,v;
}st[N];
int res;
void add(int u,int v){
    st[res].u=min(u,v);
    st[res].v=max(u,v);
    res++;
}
bool cmp(str a,str b){
    if(a.u!=b.u) return  a.u<b.u;
    else {
        return a.v<b.v;
    }
}
int id;
void tarjan(int u)
{
    dfn[u]=low[u]=++id;
    for(int i=head[u];i;i=e[i].next)
    {
        if(vis[i^1])
            continue;
        int v=e[i].to;
        vis[i]=1;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
                add(u,v);
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        addedge(a,b);
        addedge(b,a);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    sort(st,st+res,cmp);
    for(int i=0;i<res;i++)
        cout<<st[i].u<<" "<<st[i].v<<'\n';
    return 0;
}
