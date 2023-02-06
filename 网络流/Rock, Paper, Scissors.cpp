/*
题目大意：A 和 B 在玩石头剪刀布，A 会出 a1 次石头，a2 次剪刀，a3 次布，同理 B 会出 b1 次石头，b2 次剪刀，b3 次布，若对战顺序是可以进行决定的，问 A 最少能赢多少次，最多能赢多少次

题目分析：一道需要分类讨论非常复杂的贪心题，这里提供一种费用流无脑暴力的方法：

1.st -> A 的三种决策，流量分别为 a1 , a2 , a3 ，花费为 0
2.A 的石头 ->
B 的剪刀：流量为 inf ，花费为 1
B 的石头：流量为 inf ，花费为 0
B 的布：流量为 inf ， 花费为 0
3.A 的剪刀 ->
B 的剪刀：流量为 inf ，花费为 0
B 的石头：流量为 inf ，花费为 0
B 的布：流量为 inf ， 花费为 1
4.A 的布 ->
B 的剪刀：流量为 inf ，花费为 0
B 的石头：流量为 inf ，花费为 1
B 的布：流量为 inf ， 花费为 0
5.B 的三种决策 -> ed，流量分别为 b1 , b2 , b3 ，花费为 0
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <functional>
#include <deque>
#include <ctime>
using namespace std;
#define int long long
#define N 6666
#define inf 999999999999
//*************************建图
int head[N],cnt=0;
struct Node{
    int v;
    int w;//指权值
    int f;//指流量
    int next;
}edge[N*2];
void addedge(int u,int v,int flow,int cost){
    edge[cnt].v=v;
    edge[cnt].w=cost;
    edge[cnt].f=flow;
    edge[cnt].next=head[u];
    head[u]=cnt++;

    //添加反向边
    edge[cnt].v=u;
    edge[cnt].w=-cost;
    edge[cnt].f=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}

//***********************Dinic+SPFA
int ans,mincost;
int n,m,s,t;
int dis[N],vis[N];
bool spfa(int s,int t){
    for(int i=0;i<N;i++) dis[i]=inf,vis[i]=0;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            int w=edge[i].w;
            int f=edge[i].f;
            if(f>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return (dis[t]!=inf);
}
int dfs(int u,int flow){
    if(u==t){
        return flow;
    }
    int detla=flow;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        int w=edge[i].w;
        int f=edge[i].f;
        if(f>0&&!vis[v]&&dis[v]==dis[u]+w){
            int d=dfs(v,min(detla,f));
            edge[i].f-=d;edge[i^1].f+=d;
            detla-=d;
            mincost+=d*w;
            if(detla==0) break;
        }
    }
    vis[u]=0;
    return flow-detla;
}
void Dinic(){
    ans=0;
    mincost=0;
    while(spfa(s,t)){
        memset(vis,0,sizeof(vis));
        ans+=dfs(s,inf);
    }
    return ;
}
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
}
int M,A,B,C,a,b,c;
void  slove1(){
    //addedge(int u,int v,int flow,int cost)
    s=7,t=8;
    addedge(s,1,A,0);
    addedge(s,2,B,0);
    addedge(s,3,C,0);
    addedge(4,t,a,0);
    addedge(5,t,b,0);
    addedge(6,t,c,0);

    addedge(1,4,inf,0);
    addedge(1,5,inf,1);
    addedge(1,6,inf,0);

    addedge(2,4,inf,0);
    addedge(2,5,inf,0);
    addedge(2,6,inf,1);

    addedge(3,4,inf,1);
    addedge(3,5,inf,0);
    addedge(3,6,inf,0);
    Dinic();

}
signed main(){
    init();
    cin>>M>>A>>B>>C>>a>>b>>c;
    slove1();
    cout<<mincost<<" "<<min(A,b)+min(B,c)+min(C,a);
    return 0;
}
