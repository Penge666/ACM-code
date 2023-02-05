/*
题意：给x，y加一条边，问是否存在k条路径，可以来回走。

 
题解：这道题显然是树上的问题，首先我们先求出两点的最短路径，如果k小于我们的最短路径显然是不行。然后我们分类讨论的时候判断奇偶就行了。因为我们每条边来回走肯定是走偶数次的，所以不改变我们的奇偶，所以我们最后判断我们最短路的奇偶性和k是否一样就行了。

a---->b总共三种情况1.直接   2.3通过x,y转移到达


*/
#include<bits/stdc++.h>
using namespace std;
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


int check(int x,int y){
    if(y>=x&&(y-x)%2==0)
        return 1;
    else
        return 0;
}

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v,1);
        addedge(v,u,1);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        if(check(Dis(a,b),k)||check(Dis(a,x)+Dis(b,y)+1,k)||check(Dis(a,y)+Dis(b,x)+1,k)){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}
