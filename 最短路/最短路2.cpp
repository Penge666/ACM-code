/*
���⣺�����������������·���ɳڵ�����Сֵ�ĺ͡�

˼·��Floyd��һ��ѭ����ʵ����ö�ٵ��ɳڵ㡣ö����㣬ÿ����һ��Dijstra���������ɳڵ����Сֵ���ɡ�


*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int MOD=998244353;
#define N 2009
const int inf=1e18;
int dis[N][N];
int ans[N][N];
struct str{
    int V,W;
};
vector<str> G[N];
struct Node{
    int v;
    int w;
    bool operator < (const Node &r) const
    {
        return w>r.w;
    }
};
int vis[N];
void dijkstra(int id){
    priority_queue<Node> q;
    memset(vis,0,sizeof(vis));
    q.push((Node){id,0});
    //dis[id][id]=0;
    while(!q.empty()){
        struct Node temp=q.top();
        q.pop();
        int u=temp.v;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
            int to=G[u][i].V;
            int wei=G[u][i].W;
            if(dis[id][to]>dis[id][u]+wei){
                dis[id][to]=dis[id][u]+wei;
                q.push((Node){to,dis[id][to]});
                if(dis[id][to]==wei) ans[id][to]=0;
                else ans[id][to]=max(ans[id][u],u);
            }else if(dis[id][to]==dis[id][u]+wei){
                    ans[id][to]=min(ans[id][to],max(ans[id][u],u));
            }
        }
    }

}
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<=n+1;i++) G[i].clear();
        for(int i=1;i<=m;i++){
            int a,b;
            int c;
            scanf("%lld%lld%lld",&a,&b,&c);
            G[a].push_back((str){b,c});
            G[b].push_back((str){a,c});
        }
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                if(i==j)
                    dis[i][j]=0;
                else
                    dis[i][j]=inf;
                ans[i][j]=0;
            }
        }


        for(int i=1;i<=n;i++)
            dijkstra(i);
        int  res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //cout<<ans[i][j]<<" ";
                //if(i==j) continue;
                res=(res+ans[i][j])%MOD;
            }
        //    cout<<'\n';
        }

        printf("%lld\n",res%MOD);
    }

    return 0;
}
/*
*/
