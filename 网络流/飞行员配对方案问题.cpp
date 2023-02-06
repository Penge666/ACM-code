/*
给两个集合：A，B，其中A有一些元素a1,a2,a3……，B有一些元素b1,b2,b3……

其中a1想和b1，b4，……中的一个配对，a2想和b1，b250，b2500……（这些数字没什么特别含义）配对，为最优情况下能有多少组配对成功。

怎么做呢？

其实二分匹配问题可以转换为网络流问题。

把集合A当成起点，集合B当成终点，若集合一中元素a可以对应集合二中元素b，则加一条a指向b流量为一的边

新增加两个点，s和t，s有指向所有起点的边，所有终点有指向t的边，只需计算s到t的最大流，用EK算法即可。

本题要求记录配对方案，只需在找增广路时加个标记即可。
*/
//EK算法求解最大流
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            flag=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(flag)
        x=-x;
    return x;
}
#define inf 1<<30
int n,m,s,t;
struct Node{
    int v;
    int val;
    int next;
}node[201010];
int top=1,head[101010];
inline void addedge(int u,int v,int val){
    node[++top].v=v;
    node[top].val=val;
    node[top].next=head[u];
    head[u]=top;
}
int inque[101010];// 点是访问过的
struct Pre{
    int v;// 该点的前一个点（从起点过来）
    int edge;// 与该点相连的边（靠近起点的）
}pre[101010];
int ansk[1050];//标号为i的外籍飞行员和标号为ansk[i]-n的英国飞行员对应
inline bool bfs(){
    queue<int> q;
    memset(inque,0,sizeof(inque));
    memset(pre,-1,sizeof(pre));
    inque[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next){
            int d=node[i].v;
            if(!inque[d]&&node[i].val){
                pre[d].v=u;
                pre[d].edge=i;
                if(d==t)
                    return 1;
                inque[d]=1;
                q.push(d);
            }
        }
    }
    return 0;
}
int EK(){
    int ans=0;
    while(bfs()){
        int mi = inf;
        for(int i=t;i!=s;i=pre[i].v){
            mi=min(mi,node[pre[i].edge].val);
        }
        for(int i=t;i!=s;i=pre[i].v){
            ansk[pre[i].v]=i;
            node[pre[i].edge].val-=mi;
            node[pre[i].edge^1].val+=mi;
        }
        ans+=mi;
    }
    return ans;
}
int main(){
    s=2019,t=2020;
    register int i;
    m=read();n=read();
    //英国飞行员用n+i号点表示，外籍飞行员用i号点表示
    for(i=1;i<=n;i++)addedge(i+n,t,1),addedge(t,i+n,0);//使所有英国空军和汇点相连
    for(i=1;i<=m;i++)addedge(s,i,1),addedge(i,s,0);//使所有外籍空军和源点相连
    int u,v;
    while(1){
        u=read();v=read();
        if(u==-1&&v==-1) break;
        addedge(u,v+n,1);
        addedge(v+n,u,0);
    }
    printf("%d\n",EK());
    for(int i=1;i<=n;i++){
        if(ansk[i]){
            cout<<i<<" "<<ansk[i]-n<<'\n';
        }
    }
    return 0;
}
