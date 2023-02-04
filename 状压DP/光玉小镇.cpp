// 套路的状压方程QWQ


#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666 , M = 1<<17 , inf = 0x3f3f3f3f;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct str{int x,y;}t[666666];
int n,m,T,sx,sy;
int dp[M][17];
//dp[s,i]:在已经修好了状态 s 下,当前在第 i 个电线杆位置的最短时间
//dp[s|(1<<j)]=min(dp[s,i]+dis[i,j],dp[s|(1<<j)])
char mp[N][N];
int dis[66][66];
int vis[N][N];
struct Node{
  int x,y;
  int dis;
};
int Get_num(int x,int y){
  return (x-1)*n+y;
}
int bfs(int Sx,int Sy,int Tx,int Ty){
  queue<Node>q;
  memset(vis,0,sizeof(vis));
  q.push({Sx,Sy,0});
  while(!q.empty()){
    struct Node tmp=q.front();
    q.pop();
    if(vis[tmp.x][tmp.y]) continue;
    vis[tmp.x][tmp.y]=1;
    if(tmp.x==Tx&&tmp.y==Ty){
      return tmp.dis;
    }
    int x=tmp.x,y=tmp.y,ds=tmp.dis;
    for(int i=0;i<4;i++){
      int tx=x+dx[i];
      int ty=y+dy[i];
      if(tx>=1&&ty>=1&&tx<=n&&ty<=m&&mp[tx][ty]!='#'){
        q.push((Node){tx,ty,ds+1});
      }
    }
  }
  return inf;
}

signed main(){

  cin>>n>>m>>T;
  memset(dis,0x3f,sizeof(dis));
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>mp[i][j];
      if(mp[i][j]=='S') sx=i,sy=j;
      if(mp[i][j]=='T') t[cnt].x=i,t[cnt].y=j,cnt++;
    }
  }
  for(int i=0;i<cnt;i++){
    for(int j=0;j<cnt;j++){
      dis[i][j]=dis[j][i]=bfs(t[i].x,t[i].y,t[j].x,t[j].y);
    }
  }
  for(int i=0;i<cnt;i++) dis[i][cnt]=dis[cnt][i]=bfs(sx,sy,t[i].x,t[i].y);
  memset(dp,0x3f,sizeof(dp));
  for(int i=0;i<cnt;i++){
    dp[1<<i][i]=dis[i][cnt];
  }
  for(int s=0;s<(1<<cnt);s++){
    for(int i=0;i<cnt;i++){
      if(s&(1<<i)){
        for(int j=0;j<cnt;j++){
          if(!(s&(1<<j))){
            dp[s|(1<<j)][j]=min(dp[s][i]+dis[i][j],dp[s|(1<<j)][j]);
          }
        }
      }
    }
  }
  int ans=inf;
  for(int i=0;i<cnt;i++){
    ans=min(ans,dp[(1<<cnt)-1][i]+dis[cnt][i]);
  }
  if(ans==inf) cout<<"-1";
  else{
      ans+=cnt*T;
      cout<<ans;
  }

  return 0;
}
