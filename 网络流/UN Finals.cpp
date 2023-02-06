/*
    ��Ŀ�������ǣ�ÿ���Ŷ�������ѧ����ɣ�ÿ��ѧ���и��Ե�ְҵ���ã�
	Ȼ������Ŷ���ѡ���ְҵȡ�����Ŷ��������ϲ�������ɸ�ְҵ֮�е�һ����
	Ȼ����������n���Ŷ��Լ�ÿ���Ŷ�������ѧ����ְҵ���ã�
	��ĿҪ��ÿ��ְҵ���ֻ�ܱ�k���Ŷ���ѡ��
	Ȼ����Ŀ���������������ܹ��ö��ٸ��Ŷ�ѡ��ְҵ��
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#include<queue>

using namespace std;
#define int long long
const int maxn= 10090 , inf = 99999999;

//***********************Dinic�����
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
int vis[66];
signed  main(){
    creat();
    int n;
    scanf("%lld",&n);
    s=6666,t=s+1;

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int mx=0,sum=0;
        for(int j=0;j<3;j++){
            string str;cin>>str;
            for(int k=0;k<str.size();k++) vis[str[k]-'A']++;
        }
        for(int k=0;k<26;k++) mx=max(mx,vis[k]);
        for(int k=0;k<26;k++){
            if(vis[k]==mx){
                add_edge(i,k+n+1,1);
                sum++;
            }
        }
        //cout<<sum<<'\n';
        add_edge(s,i,1);
    }
    int m;
    scanf("%lld",&m);
    for(int i=0;i<26;i++) add_edge(i+n+1,t,m);
    int ans=dinic(t);
    printf("%lld",ans);
    return 0;
}
