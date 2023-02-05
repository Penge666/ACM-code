/*
 本题大意是在一个图中，求两个点之间的最短路径。这个图有n个点，n-1条边，也可以看成是一棵树。在树上求两点的最小距离，

   本题中给的是图，我们要将这个图转化成树，首先要规定根节点就是编号为1的结点。然后在此基础上求每个结点的深度和其父节点。而两个点之间的最小距离就是：两个点分别到根节点的距离相加，再减去2倍的LCA到根节点的距离。


*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
using namespace std;
#define MAXN 66666
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
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(dep,0,sizeof(dep));
    memset(fa,0,sizeof(fa));
    cnt=0;
}
signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        for(int i=1;i<n;i++){
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        dis[1]=0;//可写可不写
        dep[0]=0;//可写可不写
        dfs(1,0);
        while(m--){
            int a,b;
            scanf("%d %d", &a, &b);
            //cout<<dis[a]<<" "<<dis[b]<<" "<<2*dis[LCA(a,b)]<<'\n';
            printf("%d\n",dis[a]+dis[b]-2*dis[LCA(a,b)]);
        }

    }
    return 0;
}
