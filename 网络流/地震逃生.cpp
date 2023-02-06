//1）先建方向边
//2)Dinic{bfs,dfs}
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 66666
#define inf 99999999999
//***********************建图
int head[N],cnt=0;
struct Node{
    int v,w,next;
}edge[N*2];
void addedge(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}
//********************Dinic
int dis[N],cur[N];
int n,m,s,t;
bool bfs(int s){
    memset(dis,-1,sizeof(dis));
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(dis[v]==-1&&edge[i].w>0){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    if(dis[n]==-1) return false;
    else return true;
}
int dfs(int u,int flo){
    if(u==t)
        return flo;
    int detla=flo;
    for(int i=cur[u];i!=-1;i=edge[i].next){
        cur[u]=edge[i].next;
        int v=edge[i].v;
        if(dis[v]==dis[u]+1&&edge[i].w>0){
            int d=dfs(v,min(detla,edge[i].w));
            edge[i].w-=d;
            edge[i^1].w+=d;
            detla-=d;
            if(detla==0) break;
        }
    }
    return flo-detla;
}
int Dinic(){
    int ans=0;
    while(bfs(s)){
        for(int i=1;i<=n;i++) cur[i]=head[i];
        ans+=dfs(s,inf);
    }
    return ans;
}

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
signed main(){
    init();
    int x;
    scanf("%lld%lld%lld",&n,&m,&x);
    s=1,t=n;
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        addedge(a,b,c);
        addedge(b,a,0);
    }
    int res=Dinic();
    //printf("%lld",res);

    if(res){
        if(x%res) printf("%lld %lld\n",res,x/res+1);
        else printf("%lld %lld\n",res,x/res);
    }else{
        printf("Orz Ni Jinan Saint Cow!\n");
    }

    return 0;
}
