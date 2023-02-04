// 状压spfa即可，令 dp[i][s] 为当前在点i，走过灵玉集合为s 的最短路。

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 109 , M = 1<<15 ,inf = 0x3f3f3f3f;
struct Node{int v,w;};
int dp[N][M];//当前在i点位置上，且已经拥有j状态的最短长度
int n,m,k,arr[M],vis[N][M];
vector<Node> g[N];
void spfa(){
    memset(vis,0,sizeof(vis));
    memset(dp,inf,sizeof(dp));
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++) {
        q.push({i,1<<(arr[i])});
        dp[i][1<<(arr[i])]=0;
    }
    while(!q.empty()){
        int u=q.front().first;
        int st=q.front().second;
        q.pop();
        if(vis[u][st]) continue;
        vis[u][st]=1;
        for(int i=0;i<g[u].size();i++){
            int to=g[u][i].v;
            int w=g[u][i].w;
            if(st&(1<<arr[to])) continue;
            int now_st=st|(1<<arr[to]);
            if(dp[to][now_st]>dp[u][st]+w){
                dp[to][now_st]=dp[u][st]+w;
                q.push({to,now_st});
            }
        }
    }
}
signed main(){
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        g[a].push_back((Node){b,c});
    }
    spfa();
    int res=inf;
    for(int i=1;i<=n;i++) res=min(res,dp[i][(1<<k)-1]);
    if(res==inf) puts("Ushio!");else cout<<res<<'\n';
    return 0;
}
