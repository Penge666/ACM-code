#include<bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back
const int N = 3e5+100 , inf = 6666666666 , mod = 1e9+7;
int n,m;
struct node{
    int v,w;
};
vector<node> g[N];
vector<int> v[N];
int a[N],b[N];
int dis[N],vis[N];

int sum[N];
void dijkstra(int s){
    for(int i=0;i<=n;i++) dis[i]=inf,vis[i]=0;
    dis[s]=0;
    queue<node> q;
    q.push((node){s,0});
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(vis[t.v])
            continue;
        vis[t.v]=1;
        int u=t.v;
        for(int i=0;i<g[u].size();i++){
           int to=g[u][i].v;
            int w=g[u][i].w;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                sum[to]=sum[u];
                q.push((node){to,dis[to]});
            }else if(dis[to]==dis[u]+w){
                sum[to]=(sum[to]+sum[u])%mod;
            }
        }
    }
    return ;
}


signed main(){
    cin>>n>>m;
    sum[1]=1;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        g[a[i]].pb({b[i],1});
        g[b[i]].pb({a[i],1});
    }
    dijkstra(1);
    cout<<sum[n]%mod;
    return 0;
}
