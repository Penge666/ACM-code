#include<bits/stdc++.h>

using namespace std;
#define int long long
const double PI=acos(-1.0);
#define N 666666
#define inf 99999999999999999
vector<int> G[N];
int dis[N];
int f[N];
int n,m;
map<int,int> vis;
int getf(int v){
  if(v==f[v]) return f[v];
  else{
    f[v]=getf(f[v]);
    return f[v];
  }
}
void merge(int u,int v){
  int t1=getf(u);
  int t2=getf(v);
  if(t1!=t2) f[t2]=t1;
}

void spfa(int start){
  vis.clear();
  for(int i=0;i<n+5;i++) dis[i]=inf;
  queue<int> q;
  dis[start]=0;
  q.push(start);
  vis[start]=1;
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    vis[temp]=0;
    for(int i=0;i<G[temp].size();i++){
      int to=G[temp][i];
      if(dis[to]>dis[temp]+1){
        dis[to]=dis[temp]+1;
        if(!vis[to]){vis[to]=1;q.push(to);}
      }
    }
  }
}
signed main(){

  cin>>n>>m;
  for(int i=0;i<=n;i++) f[i]=i;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
    merge(u,v);
  }
  int sum=0;
  for(int i=1;i<=n;i++) if(i==f[i]) sum++;
  if(sum!=1){
    printf("No");
  }else{
    printf("Yes\n");
    spfa(1);
    for(int i=2;i<=n;i++){
      int ans=inf,node=0;
      for(int j=0;j<G[i].size();j++){
            if(ans>dis[G[i][j]]){
              ans=dis[G[i][j]];
              node=G[i][j];
            }
      }
      printf("%lld\n",node);
    }
  }
  return 0;
}
