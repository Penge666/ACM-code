#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 11 , M = 1<<11 , inf = 0x3f3f3f3f;
struct Node{int v,w;};
vector<Node> g[666666];
int p[N];
int n,m;
int dp[N][M];//dp[i][s]:当前在i点，已经走过了【s状态】的最短长度。
int dis[16][666666];

void spfa(int st){
    dis[st][p[st]]=0;
    queue<pair<int,int> > q;
    q.push({p[st],0});
    while(q.size()){
        int u=q.front().first;
        int w=q.front().second;
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int to=g[u][i].v;
            int wi=g[u][i].w;
            if(dis[st][to]>dis[st][u]+wi){
                dis[st][to]=dis[st][u]+wi;
                q.push({to,dis[st][to]});
            }
        }
    }
}
void init(){
    memset(dis,inf,sizeof(dis));
    for(int i=0;i<666666;i++) g[i].clear();
    memset(dp,inf,sizeof(dp));
}
signed main(){

    int T;
    cin>>T;
    while(T--){
        init();
        scanf("%lld%lld",&n,&m);
        int a,b,c;
        for(int i=0;i<m;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            g[a].push_back((Node){b,c});
            g[b].push_back((Node){a,c});
        }
        int S;
        scanf("%lld",&S);
        for(int i=1;i<=S;i++){
            scanf("%lld",&p[i]);
            spfa(i);
        }
        spfa(0);
        for(int i=0;i<=S;i++) dp[i][1<<i]=dis[0][p[i]];
        for(int s=1;s<(1<<(S+1));s++){
            for(int i=0;i<=S;i++){
                for(int j=0;j<=S;j++){
                    dp[j][s|(1<<j)]=min(dp[j][s|(1<<j)],dp[i][s]+dis[i][p[j]]);
                }
            }
        }
        cout<<dp[0][(1<<(S+1))-1]<<'\n';
    }
    return 0;
}
