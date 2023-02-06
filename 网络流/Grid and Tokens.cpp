/*
思路：最大流。关键在于构图。显然把X,Y都抽象成一个一个点。主要是如何制约N个点，将N个点置于网络中心，一 一 连线

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#include<queue>

using namespace std;
#define int long long
const int maxn= 10090 , inf = 999999999;

//***********************Dinic最大流
int head[maxn*3],sign,cur[maxn*3];
int s,t,d[maxn*3];

struct node
{
    int to,w,next;
}edge[maxn*500];
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
int vis[66];

//************Main
int h,w,n;
map<pair<int,int>,int >mp;

signed  main(){
    creat();
    int a,b,c,d;
    cin>>h>>w>>n;
    s=2*n+h+w+6,t=s+1;
    for(int i=1;i<=h;i++) add_edge(s,i,1);
    for(int i=1;i<=w;i++) add_edge(h+n*2+i,t,1);
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d;
        for(int j=a;j<=c;j++) add_edge(j,h+i,1);
        for(int j=b;j<=d;j++) add_edge(h+n+i,2*n+h+j,1);
        add_edge(h+i,h+n+i,1);
    }
    int ans=dinic(t);
    cout<<ans<<endl;
    return 0;
}
