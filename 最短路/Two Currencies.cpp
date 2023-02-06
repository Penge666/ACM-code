/*
思路：很显然这是一个单源最短路问题，我设计数组dis[i][j]表示，到达i城市还剩下j银币的最短时间。由于n的范围是2~50，且a的范围是1~50，那么从1号城市出发最多花费2500银币即可到达任意城市，那么初始的dis数组j维度最大就是2500.

       然后去跑一个普通的dij最短路，队列中存储的状态是{城市i，当前剩下的银币}。

       对于可以到达的城市，有转移状态 dis[y][w - b] = dis[cur][w] + dis(cur,v) （其中w是当前位于cur城市所剩下的银币，b为转移到y城市的银币花费数，那么转移到y城市就是w-b了）

       对于每一个可以到达的城市，也可以选择取钱，d[cur][min(w + c[cur],(ll)2500)] = d[cur][w] + t[cur]，t数组为取钱的花费时间。对于每一个城市和当前在这个城市所剩下的银币数，这种状态也需要压入队列中去，然后去转移，整体来讲很像dp的思想。


*/

#include<bits/stdc++.h>

using namespace  std;
#define inf 999999999999999999
#define int long long
#define N 666666
int dis[66][2600];
int vis[66][2600];
int n,m,s;

int C[N],D[N];
//*********************建图
int head[N];
int cnt;
struct edge{
    int u;
    int v;
    int a;
    int b;
    int next;
}e[N];
void addedge(int u,int v,int a,int b){
    e[++cnt].v=v;
    e[cnt].a=a;
    e[cnt].b=b;
    e[cnt].next=head[u];
    head[u]=cnt;
}

void init(){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2555;j++)
            dis[i][j]=inf;
    return ;
}

void dij(){
    dis[1][s]=0;
     queue<pair<int,int> > q;
     q.push(make_pair(1,s));
     while(!q.empty()){
         int u=q.front().first;
         int w=q.front().second;
         q.pop();
         for(int i=head[u];i;i=e[i].next){
             int v=e[i].v;
             int a=e[i].a;
             int b=e[i].b;
             if(w-a>=0&&dis[v][w-a]>dis[u][w]+b){
                 dis[v][w-a]=min(dis[v][w-a],dis[u][w]+b);
                 q.push(make_pair(v,w-a));
            }
        }
        if(dis[u][w]+D[u]<dis[u][min(2500*1ll,w+C[u])]){
            dis[u][min(2500*1ll,w+C[u])]=dis[u][w]+D[u];
            q.push(make_pair(u,min(2500*1ll,w+C[u])));
        }
     }
}
signed main(){

    cin>>n>>m>>s;
    s=min(s,2500*1ll);
    init();
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        addedge(a,b,c,d);
        addedge(b,a,c,d);
    }
    for(int i=1;i<=n;i++) scanf("%lld%lld",&C[i],&D[i]);
    dij();

    for(int i=2;i<=n;i++){
        int res=inf;
        for(int j=0;j<=2500;j++) res=min(res,dis[i][j]);
        printf("%lld\n",res);
    }
    return 0;
}
