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
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 6666
int mp[N][N],G[N][N];
int dis[N];
signed main(){
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        mp[u][v]=max(mp[u][v],w);
        G[u][v]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(G[i][k]&&G[k][j])
                    G[i][j]=1;
            }
        }
    }
    if(G[1][n]){
        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(mp[i][k]&&mp[k][j]){
                mp[i][j]=max(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
        cout<<mp[1][n];

    }else{
        cout<<"-1";
    }
    return 0;
}

*/
