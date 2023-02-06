/*
题意：给定一个n个点,m条边的有向图，边权为1。求把某一条边（依次从1-》m）去掉之后1到n的最短距离.
思路：这道题可以这么考虑。先求出1到N的最短路径，并记录路径。如果删掉的这条边不在最短路上，那么直接输出最短路。否则，我们暴力求出删掉边之后的最短路，判断一下即可。
时间复杂度（优先队列优化的Dij M*log(N) M约等于N^2）N^3*log(N)

*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
const int N = 3e5+100 , inf = 6666666666;
int n,m;
struct node{
    int v,w;
    bool operator <(const node &t) const
    {
        return w>t.w;
    }
};
vector<node> g[N];
vector<int> v[N],p;
int a[N],b[N];
int dis[N],vis[N],path[N];
map<pair<int,int>,int >mp,mmp;
void dijkstra(int s){
    for(int i=0;i<=n;i++) dis[i]=inf,vis[i]=0;
    dis[s]=0;
    priority_queue<node> q;
    q.push((node){s,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(vis[t.v])
            continue;
        vis[t.v]=1;
        int u=t.v;
        for(int i=0;i<g[u].size();i++){

            int to=g[u][i].v;
            int w=g[u][i].w;
            if(mmp[make_pair(u,to)])
                continue;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                path[to]=u;
                q.push((node){to,dis[to]});
            }
        }
    }
    return ;
}
signed main(){
    memset(path,-1,sizeof(path));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        g[a[i]].pb((node){b[i],1});
        v[b[i]].pb(a[i]);
    }
    dijkstra(1);
    int tot=dis[n];
    if(tot==inf){
        for(int i=0;i<m;i++) cout<<"-1"<<endl;
        exit(0);
    }

    int tmp=n;
    while(path[tmp]!=-1){
//        cout<<tmp<<" ";
        p.pb(tmp);
        tmp=path[tmp];
    }
    p.pb(1);
    reverse(p.begin(),p.end());
//    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";cout<<endl; //输出路径
//    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
//    cout<<dis[n]<<endl;
    for(int i=1;i<p.size();i++)
         mp[make_pair(p[i-1],p[i])]=1;
    for(int i=1;i<=m;i++){
        if(!mp[make_pair(a[i],b[i])]){
            cout<<tot<<endl;
        }else{
            mmp.clear();
            mmp[make_pair(a[i],b[i])]=1;
            dijkstra(1);
            if(dis[n]==inf) cout<<"-1";else cout<<dis[n];
            cout<<endl;
        }
    }
    return 0;
}
