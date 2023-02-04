/*
���⣺��n�����У�m��·��Ҫ���߹�k�Խڵ㣬��ÿ��ֻ�ܴ�һ�Խڵ��ͷ����β��ʹ·����С�������������k�Խڵ����-1.
��⣺
dp[i][1<<j]:��ǰλ��i��,���Ѿ������1<<J״̬�Ľ��׵��������С·��
dp[k][1<<j|k]=min(dp[k][1<<j|k],dp[i][1<<j]+dis(i,k)+dis(k,)); 
for(int s:0->1<<k){
    for(int i:0->k){
        for(int j:0->k){
            dp[j][s|(1<<j)]=min(dp[i][s]+dis(i->j�����)+dis(j�����->j���յ�),dp[j][s|(1<<j)]);
        }
    }
}

//dp[i][1<<j]:��ǰλ��i��,���Ѿ������1<<J״̬�Ľ��׵��������С·��
//dp[k][1<<j|k]=min(dp[k][1<<j|k],dp[i][1<<j]+dis(i,k)+dis(k,));
/*
for(int s:0->1<<k){
    for(int i:0->k){
        for(int j:0->k){
            dp[j][s|(1<<j)]=min(dp[i][s]+dis(i->j�����)+dis(j�����->j���յ�),dp[j][s|(1<<j)]);
        }
    }
}
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N  = 16666 , inf = 99999999999;
struct node{
    int u,w;
    bool operator < (const node &t) const
    {
        return w>t.w;
    }
};
struct Node{
    int v,w;
};
int n,m,k;
vector<Node> g[N];
int u[N],v[N];
int Dis[66][66];
int dp[20][(1<<18)+6];//DP[i][j]:��ʾ��ǰλ��v[i]�ϣ����Ѿ�����1<<j��״̬
//**���·
int vis[N],dis[N];
void dijkstra(int st){
    priority_queue<node> q;
    for(int i=0;i<=n+10;i++) dis[i]=inf,vis[i]=0;
    q.push((node){st,0});
    dis[st]=0;
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(vis[t.u]) continue;
        vis[t.u]=1;
        for(int i=0;i<g[t.u].size();i++){
            int v=g[t.u][i].v;
            int w=g[t.u][i].w;
            if(dis[v]>dis[t.u]+w){
                dis[v]=dis[t.u]+w;
                q.push((node){v,dis[v]});
            }
        }
    }
}
signed main(){
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    for(int i=0;i<k;i++) scanf("%lld%lld",&u[i],&v[i]);
    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
            Dis[i][j]=inf;
    for(int i=0;i<k;i++){
        dijkstra(u[i]);
        for(int j=0;j<k;j++) Dis[i][j]=dis[v[j]];
    /*    cout<<i<<'\n';
        for(int j=0;j<k;j++) cout<<Dis[i][j]<<" ";
        cout<<'\n';*/
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<k;i++) dp[i][1<<i]=Dis[i][i];
    int ans=inf;
    for(int s=0;s<(1<<k);s++){
        for(int i=0;i<k;i++){
            if(!((1<<i)&s))
                continue;
            for(int j=0;j<k;j++){
                if((1<<j)&s) continue;
                dp[j][s|(1<<j)]=min(dp[j][s|(1<<j)],dp[i][s]+Dis[j][i]+Dis[j][j]);
            }
        //    if(s+1==(1<<k)) ans=min(ans,dp[i][s]);
        }

    }

    //for(int i=0;i<k;i++) cout<<dp[i][1<<k-1]<<" ";cout<<'\n';
    for(int i=0;i<k;i++) ans=min(ans,dp[i][(1<<k)-1]);
    if(ans==inf) cout<<"-1";else cout<<ans;
    return 0;
}
*/
