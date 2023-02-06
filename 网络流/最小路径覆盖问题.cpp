/*
���⣺��С���ཻ·�����ǣ�ÿһ��·�������Ķ��������ͬ����·�����ͷ�����

 

�Ȳ�㣬Ȼ�󽨳���Դ�����㣬����Դ�����в�����ߵĵ㣬Ȼ���ұߵĵ��������㣬��Ӧ����ı߶�������ȥ���߾Ϳ��ԣ���Ȩ��Ϊ1.

 

�������Ƽ�һƪ�õĲ��ͣ�����������⣺https://www.cnblogs.com/justPassBy/p/5369930.html


*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
#define inf 0x3fffffff
using namespace std;
const int maxn=555;

//***********************Dinic�����
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
void DFS_ANS(int u,int fa){
    if(u==fa) return ;
    res.push_back(u);
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        int w=edge[i].w;
        if(v>n&&v<=2*n) v-=n;
        if(v==s||v==t||v==u) continue;
        if(!vis[v]&&w==0){
            DFS_ANS(v,u);
            break;
        }
    }
}
signed main(){

    scanf("%d%d",&n,&m);
    creat();
    s=n+n+1,t=s+1;
    int a,b;
    for(int i=1;i<=n;i++) add_edge(s,i,1);
    for(int i=1;i<=n;i++) add_edge(i+n,t,1);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        add_edge(a,b+n,1);
    }
    int ans=n-dinic(t);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            res.clear();
            DFS_ANS(i,-1);
            for(int j=0;j<res.size();j++) printf("%d ",res[j]);
            printf("\n");
        }
    }
    printf("%d",ans);
    return 0;
}
