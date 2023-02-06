#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;

const int maxn= 10090;

//***********************Dinic×î´óÁ÷
int head[maxn*3],sign,cur[maxn*3];
int s,t,d[maxn*3];

struct node
{
    int to,w,next;
}edge[maxn*500];
void creat()
{
    memset(head,-1,sizeof(head));
    sign=0;
}
void add_edge(int u,int v,int w)
{
    edge[sign].to=v;
    edge[sign].w=w;
    edge[sign].next=head[u];
    head[u]=sign++;

    edge[sign].to=u;
    edge[sign].w=0;
    edge[sign].next=head[v];
    head[v]=sign++;
}
int bfs()
{
    queue<int>q;
    memset(d,0,sizeof(d));
    d[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=head[top];~i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(edge[i].w>0&&d[to]==0)
            {
                d[to]=d[top]+1;
                if(to==t)
                    return 1;
                q.push(to);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int top,int flow)
{
    if(top==t)
        return flow;
    int ans=0,x=0;
    for(int i=cur[top];~i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(edge[i].w>0&&d[to]==d[top]+1)
        {
            x=dfs(to,min(flow-ans,edge[i].w));
            edge[i].w-=x;
            edge[i^1].w+=x;
            if(edge[i].w)
                cur[top] = i;
            ans+=x;
            if(ans==flow)
                return flow;
        }
    }
    if(ans==0)
        d[top]=0;
    return ans;
}
int dinic(int n)
{
    int ans=0;
    while(bfs())
    {
        for(int i=0;i<=n;i++)
            cur[i]=head[i];
        ans+=dfs(s,inf);
    }
    return ans;
}
//***********************
struct str{
    int u,v,w;
}st[200010];
int n,m;
bool check(int tot){
    creat();
    s=2*n+1,t=s+1;
    for(int i=1;i<=n;i++) add_edge(s,i,1),add_edge(i+n,t,1);
    for(int i=1;i<=m;i++){
        if(st[i].w<=tot){
            add_edge(st[i].u,st[i].v+n,1);
        }else{
            add_edge(st[i].u,st[i].v+n,0);
        }
    }
    int ans=dinic(t);
//    cout<<ans<<'\n';
    if(ans==n) return true;
    else return false;
}
signed  main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&st[i].u,&st[i].v,&st[i].w);
    }
    int l=0,r=1e9+1,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d",ans);



    /*
    creat();
    s=n+m+10,t=s+1;
    int sum=0;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++) add_edge(s,i,a[i]);
    for(int i=1;i<=n;i++) add_edge(m+i,t,b[i]);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            add_edge(i,j+m,1);
        }
    }
    int ans=dinic(t);
    if(sum==ans) printf("1\n");else {printf("0\n");return 0;}
    for(int i=1;i<=m;i++){
        for(int j=head[i];j!=-1;j=edge[j].next){
            int v=edge[j].to;
            int w=edge[j].w;
            if(v!=s&&w==0){
                printf("%d ",v-m);
            }
        }
        printf("\n");
    }*/
    return 0;
}
