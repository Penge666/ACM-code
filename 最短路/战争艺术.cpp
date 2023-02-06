/*
重点：对于1-n的所有点，一定存在一个点，使得ABC三国到这个点的距离最小，所有枚举每个点取最小值就行了

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666, inf = 99999999999;
struct str{
    int u,v,w;
}st[N];
struct TEMP{
    int v,w;
};
struct Node{
    int u,w;
    bool operator < (const Node &t) const
    {
        return w>t.w;
    }
};
map<int,int> mp,ans;
int n,m,a[N],MIN;
vector<TEMP> g[N];
int vis[N],dis[6][N],pre[N];
vector<int> v;
void dijkstra(int st,int temp){
    priority_queue<Node> q;
    for(int i=0;i<=10+n;i++) dis[temp][i]=inf,vis[i]=0;
    q.push((Node){st,0});
    dis[temp][st]=0;
    while(!q.empty()){
        Node tmp=q.top();
        q.pop();
        int u=tmp.u;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v;
            int w=g[u][i].w;
            if(dis[temp][v]>dis[temp][u]+w){
                dis[temp][v]=dis[temp][u]+w;
                q.push((Node){v,dis[temp][v]});
                pre[v]=u;
            }
        }
    }
}
void init(){
    for(int i=0;i<=n;i++) g[i].clear();
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        MIN=inf;
        scanf("%lld%lld",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&st[i].u,&st[i].v,&st[i].w);
            g[st[i].u].push_back((TEMP){st[i].v,st[i].w});
            g[st[i].v].push_back((TEMP){st[i].u,st[i].w});
        }
        for(int i=1;i<=3;i++) scanf("%lld",&a[i]);
        dijkstra(a[1],1);
        dijkstra(a[2],2);
        dijkstra(a[3],3);
         MIN=min(MIN,dis[1][1]+dis[2][1]+dis[3][1]);
        MIN=min(MIN,dis[1][2]+dis[2][2]+dis[3][2]);
        MIN=min(MIN,dis[1][3]+dis[2][3]+dis[3][3]);
          for(int i=1;i<=n;i++) MIN=min(MIN,dis[1][i]+dis[2][i]+dis[3][i]);
        if(MIN==inf) cout<<"-1"<<'\n';
        else cout<<MIN<<'\n';
    }
    return 0;
}
