/*
平时我们学最短路dis[i]表示从1-i的最短路是多少，那么题设添加了一个条件我们也多一维

dis[i][j]（j<=k）表示从1-i经过j天的最小花费，在跑最短路的时候判断一下是否超过K次，最

后在dis[n][1——k]遍历一遍找最小值
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6666;
#define inf  0x3f3f3f3f
int n,m,k,arr[N];
struct edge{ int v,w; };
vector<edge> g[N];
int dis[N][N];
int vis[N][N];
/*
dis(i,j)：前 i 天到达 j 点的最小花费
*/
struct Node{
    int pos,day,value;
    bool operator <(const Node &t) const
    {
        return value>t.value;
    }
};
void Dijkstra(int st){
    for(int i=0;i<=k;i++)
        for(int j=0;j<=n;j++){
            dis[i][j]=inf;
            vis[i][j]=0;
        }

    priority_queue<Node> q;
    q.push((Node){st,0,0});
    dis[0][st]=0;
    while(!q.empty()){
        struct Node t=q.top();
        q.pop();
        //cout<<"==";
        if(vis[t.day][t.pos]==1) continue;
        vis[t.day][t.pos]=1;

        int u=t.pos,val=t.value,day=t.day;
        for(int i=0;i<g[u].size();i++){
            if(day+1>k) continue;
            int v=g[u][i].v;
            int w=g[u][i].w;
            if(arr[day+1]+w+val<dis[day+1][v]){
                dis[day+1][v]=arr[day+1]+w+val;
                q.push((Node){v,day+1,dis[day+1][v]});
            }
        }
    }
}
signed main(){
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        g[a].push_back((edge){b,c});
        g[b].push_back((edge){a,c});
    }
    for(int i=1;i<=k;i++) cin>>arr[i];
    Dijkstra(1);
    int ans=inf;
    for(int i=1;i<=k;i++){
        ans=min(ans,dis[i][n]);
    //    cout<<dis[i][n]<<" ";
    }
    //cout<<'\n';

    if(ans==inf) cout<<"-1";else cout<<ans;
    return 0;
}
