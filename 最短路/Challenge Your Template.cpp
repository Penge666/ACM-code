/*
题意
给你一个随机造数据的图，数据范围比较大，让你求1-n的最短路

 

题解：
数据非常随机，所以直接跑迪杰斯特拉就好了，一下就能跑到终点然后break就好了

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 999999999999
#define M 666666
int N,Seed;
struct str{
    int to;
    int w;
};
struct node{
    int v;
    int w;
    bool operator < (const node &r) const
    {
        return w>r.w;
    }
};
vector<str> v[M];
void addEdge(int a,int b,int c){
    v[a].push_back((str){b,c});
//    v[v].push_back((str){u,w});
}
void buildGraph() {
    int nextRand = Seed;
                        // initialize random number generator
    for (int x = 1; x <= N; x++) {
                        // generate edges from Node x
        int w = x % 10 + 1;            // the weight of edges
        int d = 10 - w;                // the number of edges
        for (int i = 1; i <= d; i++) {
            addEdge(x, nextRand % N + 1, w);
                                       // add a new edge into G
            nextRand = nextRand * 233 % N;
        }
        addEdge(x, x % N + 1, w);
    }
}
void init(){
    for(int i=0;i<=N;i++) v[i].clear();
}
int vis[M],dis[M];
void dij(){
    priority_queue<node> q;
    for(int i=1;i<=N;i++){
        vis[i]=0;
        dis[i]=inf;
    }
    q.push((node){1,0});
    dis[1]=0;
    while(!q.empty()){
        struct node temp=q.top();
        q.pop();
        int u=temp.v;
        if(vis[u])
            continue;
        vis[u]=1;
        if(u==N) break;
        for(int i=0;i<v[u].size();i++){
            if(dis[v[u][i].to]>dis[u]+v[u][i].w){
                dis[v[u][i].to]=dis[u]+v[u][i].w;
                q.push((node){v[u][i].to,dis[v[u][i].to]});
            }
        }
    }
}

signed main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%lld%lld",&N,&Seed);
        init();
        buildGraph();
        dij();
        printf("%lld\n",dis[N]);
    }
    return 0;
}
