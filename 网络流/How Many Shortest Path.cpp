/*
题意：给定一个有向图，求不重叠的最大最短路数。

首先求不相交的最大路径数，我们可以直接把有向图所有边容量定为1，然后跑最大流得。题目要求最大最短路数，如果这个图上只有组成最短路的边，我们就可以用刚才的方法求得答案。于是我们就可以先跑一边最短路，然后把不满足的dist[s][i]+mp[i][j]+dist[j][t]==dist[s][t]边全部删掉（满足dist[s][i]+mp[i][j]+dist[j][t]==dist[s][t]的边一定在最短路径上）。这样就可以在这个图上求解答案了。


*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#define INF 100000000
using namespace std;
const int N=205;
const int M=30000;
int mp[N][N],dist[N][N];
struct Node{
   int v;
   int f;
   int next;
}edge[M];
int n,m,u,v,s,t,cnt,sx,ex;
int head[N],pre[N];
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].f=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].f=0;
    edge[cnt].v=u;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
bool BFS(){
  memset(pre,0,sizeof(pre));
  pre[sx]=1;
  queue<int>Q;
  Q.push(sx);
 while(!Q.empty()){
     int d=Q.front();
     Q.pop();
     for(int i=head[d];i!=-1;i=edge[i].next    ){
        if(edge[i].f&&!pre[edge[i].v]){
            pre[edge[i].v]=pre[d]+1;
            Q.push(edge[i].v);
        }
     }
  }
 return pre[ex]>0;
}
int dinic(int flow,int ps){
    int f=flow;
     if(ps==ex)return f;
     for(int i=head[ps];i!=-1;i=edge[i].next){
        if(edge[i].f&&pre[edge[i].v]==pre[ps]+1){
            int a=edge[i].f;
            int t=dinic(min(a,flow),edge[i].v);
              edge[i].f-=t;
              edge[i^1].f+=t;
            flow-=t;
             if(flow<=0)break;
        }

     }
      if(f-flow<=0)pre[ps]=-1;
      return f-flow;
}
int solve(){
    int sum=0;
    while(BFS())
        sum+=dinic(INF,sx);
    return sum;
}
int temp;
int main() {
    while(~scanf("%d",&n)){
         init();
         for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                  scanf("%d",&temp);
                  if(i==j)mp[i][j]=0;
                  else if(temp==-1)mp[i][j]=INF;
                  else
                    mp[i][j]=temp;
                    dist[i][j]=mp[i][j];
            }
         }
          scanf("%d%d",&s,&t);
          if(s!=t){
            s++;t++;
            for(int k=1;k<=n;k++)
               for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                   if(mp[i][j]<INF&&dist[s][i]+mp[i][j]+dist[j][t]==dist[s][t])
                     add(i,j,1);
                }
            }
            sx=s;ex=t;
            printf("%d\n",solve());
        }
         else
            printf("inf\n");
        }
    return 0;
}
