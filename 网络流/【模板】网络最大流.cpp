#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 99999999999
#define N 666666

int n,m,s,t;
int top;
struct Node{
    int v;
    int val;
    int next;
}node[N];
struct Pre{
    int v;//该点的前一个点；
    int edge;//与改点相连的边
}pre[N];
int head[N];
int inque[N];
void addedge(int u,int v,int w){
    node[++top].v=v;
    node[top].val=w;
    node[top].next=head[u];
    head[u]=top;
}
int bfs(){
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
                if(d==t) return 1;
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
        int mi=inf;
        for(int i=t;i!=s;i=pre[i].v)
            mi=min(mi,node[pre[i].edge].val);
        for(int i=t;i!=s;i=pre[i].v){
            node[pre[i].edge].val-=mi;
            node[pre[i].edge^1].val+=mi;
        }
        ans+=mi;
    }
    return ans;
}
signed main(){
    top=1;
    scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,0);
    }
    printf("%lld\n",EK());
    return 0;
}
