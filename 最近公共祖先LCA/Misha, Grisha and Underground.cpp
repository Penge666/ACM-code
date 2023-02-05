/*
 �ֶ���ͼ�ҹ���

��Ŀ���⣺����n����վ��m�η���

n-1�����֣���˼Ϊi-pi�ĵ�·��ͨ·��˫��

֮����m�η��ʣ����������㣬����һ�����յ㣬����������㣬�ҳ��غϵ�����·�ߣ�����غϵ������

��ʵ�����ѣ��ؼ������ȷ���غ����ĵ㣬��Ϊ�������㣬����ֱ�Ӵ������������Ȼ��ȡ���ļ��ɣ�

����a��b��c���㣻�����״�ͼ�п����������a��bΪ��㣬��ô(lca(a,c)+lca(b,c)-lca(a,b))/2�������ǵ��غϵı��ˣ���ô��Ϊ�������ߣ�ֱ���ҳ������ߵĳ���Ȼ��ȡ����Ǹ����ɣ�

��ס��(lca(a,c)+lca(b,c)-lca(a,b))/2�����ԡ�QAQ


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 666666
#define inf 0x3f3f3f3f3f3f
int head[MAXN],cnt;
struct edge{
    int to;
    int next;
}e[MAXN*2];
void add(int u,int v){
    e[++cnt].to=v;
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
        dis[e[i].to]=dis[root]+1;
        dfs(e[i].to,root);
    }
}
int LCA(int a,int b){
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
int DIS(int a,int b){
    int lca=LCA(a,b);
    return dis[a]+dis[b]-2*dis[lca];
}
int ans;

void cla(int s,int f,int t){
    ans=max(ans,(DIS(s,f)+DIS(t,f)-DIS(s,t))/2+1);
    return ;
}

signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int temp;
        scanf("%lld",&temp);
        add(i,temp);add(temp,i);
    }
    dfs(1,0);
    while(q--){
        ans=1;
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        cla(a,b,c);
        cla(a,c,b);
        cla(b,a,c);
        cla(b,c,a);
        cla(c,a,b);
        cla(c,b,a);
        printf("%lld\n",ans);
    }
    return 0;
}
