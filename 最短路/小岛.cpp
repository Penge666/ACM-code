#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 6666
int mp[N][N];
int n,m;
int dis[N],vis[N];
void BFS(){
    for(int i=1;i<=n;i++) dis[i]=-1;
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(u==i) continue;
            if(!mp[u][i])
                continue;
            if(dis[i]<dis[u]+mp[u][i]){

                dis[i]=mp[u][i]+dis[u];
                q.push(i);
            }
        }
    }
    cout<<dis[n];
}
signed main(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        mp[u][v]=max(mp[u][v],w);
    }
    BFS();
    return 0;
}
