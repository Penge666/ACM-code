/*
之前做过一个给柱子让输出需要多少点的题，找规律过的，这道题用到了： m = (n + 1) * n / 2 + (n - 1) / 2;
现在问题转化为给你点数和柱子让你构造，图的构建规则给你了，所用的最多的点给你了，可以抽象成给你构造一个图和最小路径覆盖，让你打印最小路径覆盖的每一条路径。问题转化之后，就简单了，就按照最小路径覆盖处理即可。

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
#define inf 0x3fffffff
using namespace std;
const int maxn=5555;

//***********************Dinic最大流
int head[maxn],sign,cur[maxn];
int s,t,d[maxn];
int mp[maxn][maxn];
struct node
{
    int to,w,next;
}edge[maxn*50];
void creat()
{
    memset(head,-1,sizeof(head));
    sign=0;
}
void add_edge(int u,int v,int w)
{
    edge[sign].to=v;
    edge[sign].w=w;
    edge[sign].next=head[u];
    head[u]=sign++;

    edge[sign].to=u;
    edge[sign].w=0;
    edge[sign].next=head[v];
    head[v]=sign++;
}
int bfs()
{
    queue<int>q;
    memset(d,0,sizeof(d));
    d[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=head[top];~i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(edge[i].w>0&&d[to]==0)
            {
                d[to]=d[top]+1;
                if(to==t)
                    return 1;
                q.push(to);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int top,int flow)
{
    if(top==t)
        return flow;
    int ans=0,x=0;
    for(int i=cur[top];~i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(edge[i].w>0&&d[to]==d[top]+1)
        {
            x=dfs(to,min(flow-ans,edge[i].w));
            edge[i].w-=x;
            edge[i^1].w+=x;
            if(edge[i].w)
                cur[top] = i;
            ans+=x;
            if(ans==flow)
                return flow;
        }
    }
    if(ans==0)
        d[top]=0;
    return ans;
}
int dinic(int n)
{
    int ans=0;
    while(bfs())
    {
        for(int i=0;i<=n;i++)
            cur[i]=head[i];
        ans+=dfs(s,inf);
    }
    return ans;
}
//***********************slove
map<int,int> vis;
vector<int>  res;
int n,m;
void DFS_ANS(int u,int fa){  //找线路
    if(u==fa) return ;
    res.push_back(u);
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        int w=edge[i].w;
        if(v>m&&v<=2*m) v-=m;
        if(v==s||v==t||v==u) continue;
        if(!vis[v]&&w==0){
            DFS_ANS(v,u);
            break;
        }
    }
}

signed main(){
    for(int i=1;i<=1500;i++) vis[i*i]=1;
    scanf("%d",&n);
    m=(n+1)*n/2+(n-1)/2;
    creat();
    s=m+m+1,t=s+1;
    int a,b;
    for(int i=1;i<=m;i++) add_edge(s,i,1);
    for(int i=1;i<=m;i++) add_edge(i+m,t,1);
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(vis[i+j]) add_edge(i,j+m,1);
        }
    }
    int ANS=m;
    printf("%d\n",ANS);
    int temp=dinic(t);
    vis.clear();
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            res.clear();
            DFS_ANS(i,-1);
            for(int j=0;j<res.size();j++) printf("%d ",res[j]);
            printf("\n");
        }
    }

    return 0;
}
