#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1008;
const int INF = 111111111;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
int s,t;
struct EdmondsKarp{
    int n,m;
    vector<Edge>edge; //边数的两倍
    vector<int>G[maxn]; //邻接表，G[i][j]表示i的第j条边在e数组中的序号
    int a[maxn]; //当起点到i的可改进量
    int p[maxn]; //最短路树上p的入弧编号

    void init(int n){
        for(int i=0;i<=n;i++) G[i].clear();
        edge.clear();
    }

    void AddEdge(int from,int to,int cap){
        edge.push_back(Edge(from,to,cap,0));
        edge.push_back(Edge(to,from,0,0)); //反向弧
        m=edge.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Maxflow(int s,int t){
        int flow=0;
        for(;;){
            memset(a,0,sizeof(a));
            queue<int>q;
            while(!q.empty()) q.pop();
            q.push(s);
            a[s]=INF;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e=edge[G[x][i]];
                    if(!a[e.to]&&e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) return flow;
            for(int u=t;u!=s;u=edge[p[u]].from){
                edge[p[u]].flow+=a[t];
                edge[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
    }
};

int main()
{
    int N,F,D;
    s = 0;
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        EdmondsKarp EK;
        t = N*2+F+D+1;
        EK.init(t+1);
        int f,d;
        for(int i = 1; i <= F; i++){//源点向各种食物连边
            EK.AddEdge(s,i,1);
        }
        int tm;
        for(int i = 1; i <= N; i++){
            scanf("%d%d",&f,&d);
            for(int j = 1; j <= f; j++){
                scanf("%d",&tm);
                EK.AddEdge(tm,F+i*2-1,1);//食物向喜欢它的牛连边
            }
            EK.AddEdge(F+i*2-1,F+i*2,1);//牛拆点
            for(int j = 1; j <= d; j++){
                scanf("%d",&tm);
                EK.AddEdge(F+i*2,2*N+F+tm,1);//牛向喜欢的饮料连边
            }
        }
        for(int i = 1; i <= D; i++){
            EK.AddEdge(2*N+F+i,t,1);//所有饮料向汇点连边
        }
        //puts("haha");
        int ans = EK.Maxflow(0,t);
        printf("%d\n",ans);
    }
    return 0;
}
