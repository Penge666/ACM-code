#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
using namespace std;
#define MAXN 66666
int f[MAXN];
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
void merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        f[t1]=t2;
    //    return 1;
    }
//    return 0;
}

int n,m;

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

void init(){
    for(int i=0;i<=n;i++) f[i]=i;
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(dep,0,sizeof(dep));
    memset(fa,0,sizeof(fa));
    cnt=0;
}

int DIS(int a,int b){
    int lca=LCA(a,b);
    return dis[a]+dis[b]-2*dis[lca];
}
signed main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d%*s", &a, &b, &c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        dfs(1,0);
        int q;
        scanf("%d",&q);
        while(q--){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",DIS(u,v));
        }
    }
    return 0;
}
