/*
�����Ŀ�õ���һ���ǳ�����Ҳ�ǳ�����ļ��ɣ��Ǿ��Ǽ�һ������Դ��
��һ������Դ�㣬Ȼ��ӳ���Դ����ÿ���㽨һ������ߣ���ȨΪ�õ㿧�ȼ۸��ٰ�ԭ�ȵı�Ȩ����Ϊԭ��������������·�����ȣ���Ȼ���Գ���Դ��Ϊ����ܵ�Դ���·��������ĳ���Դ�㵽ÿ�������̾�����������ȿ��ȵ���С���� ��


*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 666666 , inf = 0x3f3f3f3f;
struct Node{
    int v,w;
};
vector<Node> g[N];
int n,m,arr[N];
bool vis[N];
int dis[N];
struct str{
    int v,w;
    bool operator <(const str &t) const
    {
        return w>t.w;
    }
};
void dijkstra(int s){
    for(int i=0;i<=n;i++) dis[i]=inf,vis[i]=0;
    dis[0]=0;
    priority_queue<str> q;
    q.push((str){s,0});
    while(!q.empty()){
        str t=q.top();
        q.pop();
        if(vis[t.v]) continue;
        vis[t.v]=1;
        int u=t.v;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v;
            int w=g[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push((str){v,dis[v]});
            }
        }
    }
    return ;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back((Node){v,2*w});
        g[v].push_back((Node){u,2*w});
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        g[0].push_back((Node){i,arr[i]});
    }
    dijkstra(0);
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    return 0;
}
