/*

思路：考虑题目所给的一些限制：

1.所有点都要被遍历，且抓捕只能发生一次，那就对于点i将其拆成两个点，然后i到i'连边容量为1，费用为-INF，以保证当前点一定发生过一次抓捕

2.K支队伍不一定用完，对于0号点连边到汇点，容量为K，费用为0，将多余的流量送入汇点

3.抓捕i前要先抓i - 1，对于i'点连边到j点(j > i)，容量为1, 费用为两点间最短距离

再构建源点汇点，相应连边即可

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
#define inf 10000000
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
      //  cout<<"==";
        memset(vis,0,sizeof(vis));
        ans+=dfs(s,inf);
    }
    return ;
}



int K;int mp[110][110];
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i==j)
                mp[i][j]=0;
            else
                mp[i][j]=inf;

    return ;
}



signed main(){
    while(~scanf("%lld%lld%lld",&n,&m,&K)){
        if(!n&&!m&&!K) break;
        init();
        int a,b,c;
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            mp[a][b]=mp[b][a]=min(mp[a][b],c);
           // addedge(a,b,c,d);
           // addedge(b,a,0,-d);
        }
        for(int k=0;k<=n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
        }
        s=2*n+1;t=s+1;//建立超级源点，超级汇点
        addedge(s,0,K,0);
        addedge(0,t,K,0);
        for(int i=1;i<=n;i++){
            addedge(0,i,1,mp[0][i]);
            addedge(i+n,t,1,mp[0][i]);
            addedge(i,i+n,1,-inf);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                addedge(i+n,j,1,mp[i][j]);
            }
        }
    //
        Dinic();
           printf("%lld\n",mincost+n*inf);
    }
    return 0;
}
