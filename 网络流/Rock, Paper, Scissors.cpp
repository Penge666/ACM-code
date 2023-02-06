/*
��Ŀ���⣺A �� B ����ʯͷ��������A ��� a1 ��ʯͷ��a2 �μ�����a3 �β���ͬ�� B ��� b1 ��ʯͷ��b2 �μ�����b3 �β�������ս˳���ǿ��Խ��о����ģ��� A ������Ӯ���ٴΣ������Ӯ���ٴ�

��Ŀ������һ����Ҫ�������۷ǳ����ӵ�̰���⣬�����ṩһ�ַ��������Ա����ķ�����

1.st -> A �����־��ߣ������ֱ�Ϊ a1 , a2 , a3 ������Ϊ 0
2.A ��ʯͷ ->
B �ļ���������Ϊ inf ������Ϊ 1
B ��ʯͷ������Ϊ inf ������Ϊ 0
B �Ĳ�������Ϊ inf �� ����Ϊ 0
3.A �ļ��� ->
B �ļ���������Ϊ inf ������Ϊ 0
B ��ʯͷ������Ϊ inf ������Ϊ 0
B �Ĳ�������Ϊ inf �� ����Ϊ 1
4.A �Ĳ� ->
B �ļ���������Ϊ inf ������Ϊ 0
B ��ʯͷ������Ϊ inf ������Ϊ 1
B �Ĳ�������Ϊ inf �� ����Ϊ 0
5.B �����־��� -> ed�������ֱ�Ϊ b1 , b2 , b3 ������Ϊ 0
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <functional>
#include <deque>
#include <ctime>
using namespace std;
#define int long long
#define N 6666
#define inf 999999999999
//*************************��ͼ
int head[N],cnt=0;
struct Node{
    int v;
    int w;//ָȨֵ
    int f;//ָ����
    int next;
}edge[N*2];
void addedge(int u,int v,int flow,int cost){
    edge[cnt].v=v;
    edge[cnt].w=cost;
    edge[cnt].f=flow;
    edge[cnt].next=head[u];
    head[u]=cnt++;

    //��ӷ����
    edge[cnt].v=u;
    edge[cnt].w=-cost;
    edge[cnt].f=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}

//***********************Dinic+SPFA
int ans,mincost;
int n,m,s,t;
int dis[N],vis[N];
bool spfa(int s,int t){
    for(int i=0;i<N;i++) dis[i]=inf,vis[i]=0;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            int w=edge[i].w;
            int f=edge[i].f;
            if(f>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return (dis[t]!=inf);
}
int dfs(int u,int flow){
    if(u==t){
        return flow;
    }
    int detla=flow;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        int w=edge[i].w;
        int f=edge[i].f;
        if(f>0&&!vis[v]&&dis[v]==dis[u]+w){
            int d=dfs(v,min(detla,f));
            edge[i].f-=d;edge[i^1].f+=d;
            detla-=d;
            mincost+=d*w;
            if(detla==0) break;
        }
    }
    vis[u]=0;
    return flow-detla;
}
void Dinic(){
    ans=0;
    mincost=0;
    while(spfa(s,t)){
        memset(vis,0,sizeof(vis));
        ans+=dfs(s,inf);
    }
    return ;
}
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
}
int M,A,B,C,a,b,c;
void  slove1(){
    //addedge(int u,int v,int flow,int cost)
    s=7,t=8;
    addedge(s,1,A,0);
    addedge(s,2,B,0);
    addedge(s,3,C,0);
    addedge(4,t,a,0);
    addedge(5,t,b,0);
    addedge(6,t,c,0);

    addedge(1,4,inf,0);
    addedge(1,5,inf,1);
    addedge(1,6,inf,0);

    addedge(2,4,inf,0);
    addedge(2,5,inf,0);
    addedge(2,6,inf,1);

    addedge(3,4,inf,1);
    addedge(3,5,inf,0);
    addedge(3,6,inf,0);
    Dinic();

}
signed main(){
    init();
    cin>>M>>A>>B>>C>>a>>b>>c;
    slove1();
    cout<<mincost<<" "<<min(A,b)+min(B,c)+min(C,a);
    return 0;
}
