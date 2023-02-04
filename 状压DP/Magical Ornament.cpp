/*
仔细读题后会发现序列的顺序没有要求，只要有经过就行，根据数据范围容易想到状压DP

dp[20][(1<<17)+100];
dp[i][1<<j]:当前正在处理第i位，并且已经摆好了1<<j的状态 
枚举k，k为不在(1<<j)的状态 
dp[i][1<<j|k]=min(dp[i][1<<j|k],dp[i][1<<j]+dis(i,k))
*/
#include<bits/stdc++.h>

using namespace std;
#define  pb push_back
#define int long long

const int N = 3e5+100 , inf = 0x3f3f3f3f , mod = 998244353;

struct node{
    int u,w;
    bool operator < (const node &r) const
    {
        return w>r.w;
    }
};
int n,m,k,c[N];
vector<int> g[N];
int dp[20][(1<<17)+100];
int dis[20][N];
int vis[N];
int dt[N];
void dijkstra(int st){
    priority_queue<node> q;
    for(int i=0;i<=n;i++) dt[i]=inf,vis[i]=0;
    dt[st]=0;
    q.push((node){st,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(vis[t.u])
            continue;
        vis[t.u]=1;
        for(int i=0;i<g[t.u].size();i++){
            int to=g[t.u][i];
            if(dt[to]>dt[t.u]+1){
                dt[to]=dt[t.u]+1;
                q.push((node){to,dt[to]});
            }
        }
    }
    return ;
}
signed main(){
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>k;
    for(int i=0;i<k;i++) cin>>c[i];
    for(int i=0;i<k;i++){
        dijkstra(c[i]);
        for(int j=0;j<k;j++){
            dis[i][j]=dis[j][i]=dt[c[j]];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<k;i++) dp[i][1<<i]=0;
    for(int s=0;s<(1<<k);s++){
        for(int i=0;i<k;i++){
            if(!((1<<i)&s))
                continue;
            for(int j=0;j<k;j++){
                if((1<<j)&s) continue;
                dp[j][s|(1<<j)]=min(dp[i][s]+dis[i][j],dp[j][s|(1<<j)]);
            }
        }
    }
    int ans=inf;
    for(int i=0;i<k;i++) ans=min(ans,dp[i][(1<<k)-1]);
    if(ans==inf) cout<<"-1";
    else cout<<1+ans;
     return 0;
}

/*

*/
