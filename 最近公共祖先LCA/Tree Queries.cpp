/*
嘿嘿·自己补出来的感觉真好 

思路：

1.将各个节点高度排序。
2.以最深的那个节点为特定节点
3.对于每个点与特定节点进行LCA
4.LCA若等于该点则继续。否则判读距离。距离>1则NO。

大板子套一套


*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
using namespace std;
#define int long long
#define MAXN 266666
int f[MAXN];
struct str{
    int node;
    int height;
}q[MAXN];
int hi[MAXN];
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
map<int,int> VIS;
void init(){
    VIS.clear();
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

void dfs_height(int root,int dis){
    if(VIS[root]){
        return ;
    }
    VIS[root]=1;
    hi[root]=dis;
    for(int i=head[root];i;i=e[i].next){
        dfs_height(e[i].to,dis+1);
    }
}
bool cmp(str a,str b){
    return a.height>b.height;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    init();
    for(int i=1;i<n;i++){
        int A,B;
        cin>>A>>B;
        addedge(A,B,1);
        addedge(B,A,1);
    }

    dfs_height(1,0);
    dfs(1,0);
    while(m--){
        int F=1;
        int K;
        scanf("%lld",&K);
        for (int i=1;i<=K;i++){
            scanf("%lld",&q[i].node);
            q[i].height=hi[q[i].node];
        }
        sort(q+1,q+1+K,cmp);
        int sp=q[1].node;
        for(int i=2;i<=K;i++){
            int tot=LCA(sp,q[i].node);
            if(DIS(tot,q[i].node)>1){
                F=0;break;
            }
        }
        if(F) printf("YES");else printf("NO");
        printf("\n");
    }
    return 0;
}

/*
1.将各个节点高度排序。
2.以最深的那个节点为特定节点
3.对于每个点与特定节点进行LCA
4.LCA若等于该点则继续。否则判读距离。距离>1则NO
*/
