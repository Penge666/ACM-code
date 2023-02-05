/*
���⣺��x��y��һ���ߣ����Ƿ����k��·�������������ߡ�

 
��⣺�������Ȼ�����ϵ����⣬���������������������·�������kС�����ǵ����·����Ȼ�ǲ��С�Ȼ�����Ƿ������۵�ʱ���ж���ż�����ˡ���Ϊ����ÿ���������߿϶�����ż���εģ����Բ��ı����ǵ���ż��������������ж��������·����ż�Ժ�k�Ƿ�һ�������ˡ�

a---->b�ܹ��������1.ֱ��   2.3ͨ��x,yת�Ƶ���


*/
#include<bits/stdc++.h>
using namespace std;
#define N 666666
#define MAXN 666666

int head[MAXN],cnt;
struct edge{
    int to;
    int next;
    int w;
}e[MAXN*2];
void addedge(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}

int dep[MAXN],dis[MAXN],fa[MAXN][26];
void dfs(int root,int pre){
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
        fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].next){
        if(e[i].to==pre) continue;
        dis[e[i].to]=dis[root]+e[i].w;
        dfs(e[i].to,root);
    }
}
int LCA(int a,int b)
{
    if(dep[a]<dep[b])
        swap(a,b);
    for(int i=19;i>=0;i--)
    {
        if(dep[a]-(1<<i)>=dep[b])
            a=fa[a][i];
    }
    if(a==b)
        return a;
    for(int i=19;i>=0;i--)
    {
        if(fa[a][i]!=fa[b][i])
        {
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}



int Dis(int a,int b){
    int lca=LCA(a,b);
    return dis[a]+dis[b]-2*dis[lca];
}


int check(int x,int y){
    if(y>=x&&(y-x)%2==0)
        return 1;
    else
        return 0;
}

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v,1);
        addedge(v,u,1);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        if(check(Dis(a,b),k)||check(Dis(a,x)+Dis(b,y)+1,k)||check(Dis(a,y)+Dis(b,x)+1,k)){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}
