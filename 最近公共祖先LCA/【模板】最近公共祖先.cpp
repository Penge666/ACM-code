//博客推荐：

//https://blog.csdn.net/Q_M_X_D_D_/article/details/89924963


#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define int long long
const int maxn=500005;
int root,n,m,a,b,c;
//保存图结构
struct node
{
    int to;
    int next;
}e[2*maxn];
int head[maxn];
int cnt;
void add(int a,int b)
{
    e[++cnt].to=b;
    e[cnt].next=head[a];
    head[a]=cnt;
}

//遍历图，求出各节点的深度，并求出fa数组
int fa[maxn][20],dep[maxn];
void dfs(int root,int pre)
{
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
        fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].next)
    {
        if(e[i].to!=pre)
            dfs(e[i].to,root);
    }
}
//查询函数
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
signed  main()
{
    cin>>n>>m>>root;
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(root,0);
    while(m--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",LCA(a,b));
    }
    return 0;
}
