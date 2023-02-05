#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
#define MAXN 666666
int head[MAXN],cnt;
struct edge{
    int to;
    int next;
    int w;
}e[MAXN*2];
void addedge(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int dep[MAXN],dis[MAXN],fa[MAXN][26];
void dfs(int root,int pre){
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
        fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].next){
        if(e[i].to==pre) continue;
        dis[e[i].to]=dis[root]+e[i].w;
        dfs(e[i].to,root);
    }
}
int LCA(int a,int b)
{
    if(dep[a]<dep[b])
        swap(a,b);
    for(int i=19;i>=0;i--)
    {
        if(dep[a]-(1<<i)>=dep[b])
            a=fa[a][i];
    }
    if(a==b)
        return a;
    for(int i=19;i>=0;i--)
    {
        if(fa[a][i]!=fa[b][i])
        {
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}
int Dis(int a,int b){
    int lca=LCA(a,b);
    return dis[a]+dis[b]-2*dis[lca];
}
int arr[N];
vector<int> v[N];
bool cmp(int a,int b){
    return dep[a]>dep[b];
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int type;
        cin>>type;
        v[type].push_back(i);
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v,1);
        addedge(v,u,1);
    }

    dfs(1,0);
    int res=0;
    for(int i=1;i<=n;i++){
        if(!v[i].size()) continue;
        //cout<<"==";
        sort(v[i].begin(),v[i].end(),cmp);
        int node=v[i][0];
        for(int j=0;j<v[i].size();j++){
            int temp=v[i][j];
            int dis=Dis(node,temp);
            res=max(res,dis*dis);
        }
    }
    cout<<res;
    return 0;
}
