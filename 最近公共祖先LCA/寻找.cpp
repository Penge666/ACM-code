/*
 https://ac.nowcoder.com/acm/contest/558/D

画图判断一下。然后开始分类讨论即可


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 666666
#define inf 0x3f3f3f3f3f3f
int head[MAXN],cnt;
struct edge{
    int to;
    int next;
}e[MAXN*2];
void add(int u,int v){
    e[++cnt].to=v;
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
        dis[e[i].to]=dis[root]+1;
        dfs(e[i].to,root);
    }
}
int LCA(int a,int b){
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
    int n;
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    int q;
    scanf("%lld",&q);
    while(q--){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        int c_ab=LCA(a,b);
        int c_bc=LCA(c,b);
        int c_ac=LCA(a,c);
        if(c_ac==c_bc){
            printf("%lld\n",c_ab);
        }else{
            int ans=0;
            int MIN=inf;
            int dis=0;
            dis=DIS(c,c_ac);
            if(dis<MIN){
                MIN=dis;
                ans=c_ac;
            }
            dis=DIS(c,c_bc);
            if(dis<MIN){
                MIN=dis;
                ans=c_bc;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
