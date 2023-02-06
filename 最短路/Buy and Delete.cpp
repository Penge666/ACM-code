/*
猜个结论。答案只能0，1，2这3个数。如果一条边都买不起，则直接输出0.如果图中存在环路并能买的起，则输出2.否则输出1.（找环路可以用最短路实现）

*/
#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define int long long
const int N = 2e3+100 , M = 5e3+100 , inf = 0x3f3f3f3f;
struct node{
    int v,w;
    bool operator < (const node &t) const
    {
        return w>t.w;
    }
};
int n,m,c;
int u[M],v[M],p[M];
vector<node> g[N];
int vis[N];
int dis[N][N];
void dijkstra(int s){
    for(int i=1;i<=n;i++) vis[i]=0,dis[s][i]=inf;
    dis[s][s]=0;
    priority_queue<node> q;
    q.push({s,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        int o=t.v;
        if(vis[o]) continue;
        vis[o]=1;
        for(int i=0;i<g[o].size();i++){
            int to=g[o][i].v;
            int wo=g[o][i].w;
            if(dis[s][to]>dis[s][o]+wo){
                dis[s][to]=min(dis[s][to],dis[s][o]+wo);
                q.push({to,dis[s][to]});
            }
        }
    }
    return ;
}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&c);
    int mx=inf;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u[i],&v[i],&p[i]);
        g[u[i]].pb({v[i],p[i]});
        mx=min(mx,p[i]);
    }
    if(c<mx){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    int cur=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(dis[i][j]!=inf&&dis[j][i]!=inf){
                //cout<<i<<" "<<j<<endl;
                cur=min(cur,dis[i][j]+dis[j][i]);
            }
        }
    }
//    cout<<cur<<endl;
    if(cur!=inf&&c>=cur){
        cout<<"2"<<endl;
    }else{
        cout<<"1"<<endl;
    }
    return 0;
}
