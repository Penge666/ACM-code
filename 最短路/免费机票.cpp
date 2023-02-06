/*
���·�ı��Σ���� b,�յ�e ���b�����е����̾���dist1[] e�����������̾���dist2[]

ö�����е���ѻ�Ʊ���ܸ�����̾����˵����Ҫʹ�����Ż�Ʊ


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 66666
#define inf 99999999999999
struct str{
    int  v,w;
     bool operator <(const str &r) const
    {
        return w>r.w;
    }
};
int n;
struct edge{
    int x,y;
};
vector<edge>v[N];
int dis[N],diss[N],dise[N];
int vis[N];
void dij(int st){
    priority_queue<str> q;
    while(!q.empty()) q.pop();
    for(int i=1;i<=n+1;i++) dis[i]=inf,vis[i]=0;
    q.push((str){st,0});
    vis[st]=1;
    dis[st]=0;
    while(!q.empty()){
        struct str temp=q.top();
        q.pop();
        for(int i=0;i<v[temp.v].size();i++){
            int to=v[temp.v][i].x;
            if(dis[to]>dis[temp.v]+v[temp.v][i].y){
                dis[to]=dis[temp.v]+v[temp.v][i].y;
                if(!vis[to]){
                    vis[to]=1;
                    q.push((str){to,dis[to]});
                }

            }
        }
    }
//  return ;
}
void init(){
    for(int i=0;i<=n;i++) v[i].clear();
}
signed main(){
    int s,e;
    cin>>n>>s>>e;
    init();
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back((edge){b,c});
        v[b].push_back((edge){a,c});
    }
    dij(s);
    for(int i=1;i<=n;i++) diss[i]=dis[i];
    dij(e);
    for(int i=1;i<=n;i++) dise[i]=dis[i];
    int k;
    cin>>k;
    int F=0;
    int ans=diss[e];
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        int ans1=diss[a]+dise[b];//ö�ٺܺõ���������ȵ����
        int ans2=diss[b]+dise[a];
        int anss=min(ans1,ans2);
        if(ans>anss)
        {
            F=1;
            ans=min(ans,anss);
        }
    }
    if(F){
        cout<<"Yes"<<'\n';
        cout<<ans;
    }else{
        cout<<"No"<<'\n';
        cout<<ans;
    }
    return 0;
}
