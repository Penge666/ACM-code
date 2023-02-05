#include<bits/stdc++.h>
using namespace std;
#define N 666666
#define MAXN 666666
int n,m;
int head[MAXN],cnt;
struct edge{
    int to;
    int next;
    int w;
}e[MAXN*2];
void add(int u,int v,int w){
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
int DIS(int a,int b){
    int lca=LCA(a,b);
    return dis[a]+dis[b]-2*dis[lca];
}
signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b,1);
        add(b,a,1);
    }
    dfs(1,0);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int cost=999999999;int pos=0;
        int t1,t2;
        t1=LCA(a,b);t2=DIS(a,t1)+DIS(b,t1)+DIS(c,t1);
        if(t2<cost){
            cost=t2;
            pos=t1;
        }
        t1=LCA(a,c);t2=DIS(a,t1)+DIS(b,t1)+DIS(c,t1);
        if(t2<cost){
            cost=t2;
            pos=t1;
        }
        t1=LCA(b,c);t2=DIS(a,t1)+DIS(b,t1)+DIS(c,t1);
        if(t2<cost){
            cost=t2;
            pos=t1;
        }
        printf("%d %d\n",pos,cost);
    }
    return 0;
}
