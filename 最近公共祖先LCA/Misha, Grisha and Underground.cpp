/*
 手动画图找规律

题目大意：给出n个车站，m次访问

n-1个数字，意思为i-pi的道路是通路（双向）

之后是m次访问，输入三个点，任意一个是终点，另两个是起点，找出重合点最多的路线，输出重合点的数量

其实并不难，关键是如何确定重合最多的点，因为就三个点，可以直接处理处三个情况，然后取最大的即可；

对于a，b，c三点；很容易从图中看到，如果以a，b为起点，那么(lca(a,c)+lca(b,c)-lca(a,b))/2就是他们的重合的边了，那么因为有三条边，直接找出三条边的长度然后取最长的那个即可：

记住：(lca(a,c)+lca(b,c)-lca(a,b))/2的特性。QAQ


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
int ans;

void cla(int s,int f,int t){
    ans=max(ans,(DIS(s,f)+DIS(t,f)-DIS(s,t))/2+1);
    return ;
}

signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int temp;
        scanf("%lld",&temp);
        add(i,temp);add(temp,i);
    }
    dfs(1,0);
    while(q--){
        ans=1;
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        cla(a,b,c);
        cla(a,c,b);
        cla(b,a,c);
        cla(b,c,a);
        cla(c,a,b);
        cla(c,b,a);
        printf("%lld\n",ans);
    }
    return 0;
}
