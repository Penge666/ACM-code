//大意：给你一个无向图，k个特殊点，你要在两个不同的特殊点直接连一条无向边，使得1?>n1->n1?>n的最短路最长。

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
#define inf 99999999999
int n,m,k;
int arr[N];
int dis[6][N];
int vis[N];
vector<int> v[N];
vector<pair<int,int> > res;
void bfs(int x,int st){
    memset(vis,0,sizeof(vis));
//    for(int i=1;i<=n;i++) dis[x][i]=inf;
    queue<int> q;
    dis[x][st]=0;
    vis[st]=1;
    q.push(st);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            if(!vis[to]){
                vis[to]=1;
                dis[x][to]=dis[x][t]+1;
                q.push(to);
            }
        }
    }
}
signed  main(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) cin>>arr[i];
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(0,1);
    bfs(1,n);
    for(int i=1;i<=k;i++){
        res.push_back(make_pair(dis[0][arr[i]]-dis[1][arr[i]],arr[i]));
    }
    sort(res.begin(),res.end());
    int ans=0;
    int temp=0;
    for(int i=0;i<res.size();i++){
        if(i){
            ans=max(ans,temp+dis[1][res[i].second]+1);
        }
        temp=max(temp,dis[0][res[i].second]);
    }
    cout<<min(ans,dis[0][n]);
    return 0;
}
