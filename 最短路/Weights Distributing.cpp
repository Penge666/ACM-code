/*
����n���㣬m���ߣ���m����Ȩ�������a�ߵ�b���ٴ�b�ߵ�c ��̵�·���Ƕ���

�е���·�ˣ�ö�����е㡣
 ������Ҫ��a�ߵ�b,�ٴ�b�ߵ�c����������м���һ���ظ���·����ô����a->��->x->��->b->��->x->��->c�����Ƿ���b��x���������ߵģ���ô��һ��
·��Ҫ���Ȱ��Ż���С�ģ�ʣ�µ�����������С������������С���ѡ�����DIJ��ͼ�еĵ㵽abc������ľ����������ö�����x�㣬�Ϳ��ԡ�

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666, inf = 99999999999999999;
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
int cost[N];
map<int,int> mp,ans;
int n,m,a[N],MIN;
vector<TEMP> g[N];
int s[N];
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
        int ans=inf;
        init();
        int A,B,C,ss=0;
        scanf("%lld%lld%lld%lld%lld",&n,&m,&A,&B,&C);
        s[0]=0;
        for(int i=1;i<=m;i++) scanf("%lld",&cost[i]);
        sort(cost+1,cost+1+m);
        for(int i=1;i<=m;i++) s[i]=s[i-1]+cost[i];
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&st[i].u,&st[i].v);
            st[i].w=1;
            g[st[i].u].push_back((TEMP){st[i].v,st[i].w});
            g[st[i].v].push_back((TEMP){st[i].u,st[i].w});
        }
        dijkstra(A,1);
        dijkstra(B,2);
        dijkstra(C,3);
          for(int i=1;i<=n;i++){
              if(dis[1][i]+dis[2][i]+dis[3][i]>m) continue;
              int res=s[dis[2][i]]+s[dis[1][i]+dis[2][i]+dis[3][i]];
              //cout<<res<<'\n';
            ans=min(ans,res);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
