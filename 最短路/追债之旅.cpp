/*
ƽʱ����ѧ���·dis[i]��ʾ��1-i�����·�Ƕ��٣���ô���������һ����������Ҳ��һά

dis[i][j]��j<=k����ʾ��1-i����j�����С���ѣ��������·��ʱ���ж�һ���Ƿ񳬹�K�Σ���

����dis[n][1����k]����һ������Сֵ
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
dis(i,j)��ǰ i �쵽�� j �����С����
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
