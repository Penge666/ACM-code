#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n,s[300005];
const ll inf=0x7fffffffffffff;
struct Edge{
    int to,cost,id;
    Edge(int T,int C,int D):to(T),cost(C),id(D){}
};
//(c[]数组用来存取与该点连接的边的cost，s[]数组用来存取与该点连接的边的编号):
typedef pair<long long,int> P;
vector<Edge>G[300005];
ll d[300005],c[300005];
void dij(int u){
    fill(d,d+n+1,inf);
    fill(c,c+n+1,inf);
    d[u]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(d[u],u));
    while(!q.empty()){
        P p=q.top();
        q.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            Edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                s[e.to]=e.id;
                c[e.to]=e.cost;
                q.push(P(d[e.to],e.to));
            }
            else if(d[e.to]==d[v]+e.cost&&c[e.to]>e.cost){
                s[e.to]=e.id;
                c[e.to]=e.cost;
            }
        }
    }
}
int main(){
    int u,v,co;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&co);
        G[u].push_back(Edge(v,co,i));
        G[v].push_back(Edge(u,co,i));
    }
    scanf("%d",&u);
    dij(u);
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(i!=u) sum+=c[i];
    }
    cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        if(i!=u) cout<<s[i]<<' ';
    }
   return 0;
}
