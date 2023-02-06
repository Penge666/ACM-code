/*
˼·������Ȼ����һ����Դ���·���⣬���������dis[i][j]��ʾ������i���л�ʣ��j���ҵ����ʱ�䡣����n�ķ�Χ��2~50����a�ķ�Χ��1~50����ô��1�ų��г�����໨��2500���Ҽ��ɵ���������У���ô��ʼ��dis����jά��������2500.

       Ȼ��ȥ��һ����ͨ��dij���·�������д洢��״̬��{����i����ǰʣ�µ�����}��

       ���ڿ��Ե���ĳ��У���ת��״̬ dis[y][w - b] = dis[cur][w] + dis(cur,v) ������w�ǵ�ǰλ��cur������ʣ�µ����ң�bΪת�Ƶ�y���е����һ���������ôת�Ƶ�y���о���w-b�ˣ�

       ����ÿһ�����Ե���ĳ��У�Ҳ����ѡ��ȡǮ��d[cur][min(w + c[cur],(ll)2500)] = d[cur][w] + t[cur]��t����ΪȡǮ�Ļ���ʱ�䡣����ÿһ�����к͵�ǰ�����������ʣ�µ�������������״̬Ҳ��Ҫѹ�������ȥ��Ȼ��ȥת�ƣ�������������dp��˼�롣


*/

#include<bits/stdc++.h>

using namespace  std;
#define inf 999999999999999999
#define int long long
#define N 666666
int dis[66][2600];
int vis[66][2600];
int n,m,s;

int C[N],D[N];
//*********************��ͼ
int head[N];
int cnt;
struct edge{
    int u;
    int v;
    int a;
    int b;
    int next;
}e[N];
void addedge(int u,int v,int a,int b){
    e[++cnt].v=v;
    e[cnt].a=a;
    e[cnt].b=b;
    e[cnt].next=head[u];
    head[u]=cnt;
}

void init(){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2555;j++)
            dis[i][j]=inf;
    return ;
}

void dij(){
    dis[1][s]=0;
     queue<pair<int,int> > q;
     q.push(make_pair(1,s));
     while(!q.empty()){
         int u=q.front().first;
         int w=q.front().second;
         q.pop();
         for(int i=head[u];i;i=e[i].next){
             int v=e[i].v;
             int a=e[i].a;
             int b=e[i].b;
             if(w-a>=0&&dis[v][w-a]>dis[u][w]+b){
                 dis[v][w-a]=min(dis[v][w-a],dis[u][w]+b);
                 q.push(make_pair(v,w-a));
            }
        }
        if(dis[u][w]+D[u]<dis[u][min(2500*1ll,w+C[u])]){
            dis[u][min(2500*1ll,w+C[u])]=dis[u][w]+D[u];
            q.push(make_pair(u,min(2500*1ll,w+C[u])));
        }
     }
}
signed main(){

    cin>>n>>m>>s;
    s=min(s,2500*1ll);
    init();
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        addedge(a,b,c,d);
        addedge(b,a,c,d);
    }
    for(int i=1;i<=n;i++) scanf("%lld%lld",&C[i],&D[i]);
    dij();

    for(int i=2;i<=n;i++){
        int res=inf;
        for(int j=0;j<=2500;j++) res=min(res,dis[i][j]);
        printf("%lld\n",res);
    }
    return 0;
}
