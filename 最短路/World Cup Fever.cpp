/*
最短路问题
首先预处理出 team1 的任意两个队员是否相距为 1（相距为 1 的条件为 team1 或 team2 中
除该两个队员之外的任意一个队员均不在该两个队员形成的线段上），如果相距为 1 将他们
的的距离设置为 1,否则将他们的距离设置为无穷大然后采用 Floyd 求出 1 到 n 的最短路径
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n;
struct node{
 int x,y; }team1[15],team2[15];
int dis[15][15];
bool between(node a,node b,node c){
 if(c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x)
 &&c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y)
 &&(c.y-a.y)*(b.x-a.x)==(b.y-a.y)*(c.x-a.x))
 return true;
 return false; }
bool check(int a,int b){
 for(int i=1;i<=n;i++)
 if(a!=i&&b!=i&&between(team1[a],team1[b],team1[i])) return
false;
 for(int i=1;i<=n;i++)
 if(between(team1[a],team1[b],team2[i])) return false;
 return true; }
int main(){
 cin>>n;
 for(int i=1;i<=n;i++)cin>>team1[i].x>>team1[i].y;
 for(int i=1;i<=n;i++)cin>>team2[i].x>>team2[i].y;
 
 for(int i=1;i<=n;i++){
 for(int j=1;j<=n;j++){
 if(i==j) dis[i][j]=0;
 else if(check(i,j)) dis[i][j]=1;
 else dis[i][j]=INF;
 }
 }
 
 for(int k=1;k<=n;k++){
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
         dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
     }
    }
 }
 if(dis[1][n]==INF) puts("-1");
 else cout<<dis[1][n]<<endl;
 return 0; }
