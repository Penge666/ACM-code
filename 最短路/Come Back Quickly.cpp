/*
���⣺����һ������ͼ������ÿһ����㣬ȷ�������������������һ�����������߻ص�����������·���ĳ��ȡ�
˼·�����������Ե��ܿ��������·�����Զ�ÿ���㶼��һ��Dijkstra������ö��ȡ��Сֵ���ӵ㣺ע���Ի����رߡ�
ʱ�临�Ӷȣ�O��M*log(N)*N��N:���� M������
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back
const int N = 7e3+100 , inf = 6666666666 , mod = 1e9+7;
int n,m;
struct node{
    int v,w;
    bool operator <(const node &t) const
    {
        return w>t.w;
    }
};
vector<node> g[N];
int a[N],b[N],c[N];
int dis[N][N],vis[N];


void dijkstra(int s){
    for(int i=0;i<=n;i++) dis[s][i]=inf,vis[i]=0;
    dis[s][s]=0;
    priority_queue<node> q;
    q.push((node){s,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(vis[t.v])
            continue;
        vis[t.v]=1;
        int u=t.v;
        for(int i=0;i<g[u].size();i++){
           int to=g[u][i].v;
            int w=g[u][i].w;
            if(dis[s][to]>dis[s][u]+w){
                dis[s][to]=dis[s][u]+w;
                q.push((node){to,dis[s][to]});
            }
        }
    }
    return ;
}

map<pair<int,int> ,int> mp;
int self[N];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]==b[i]){
            if(self[a[i]]==0)
                self[a[i]]=c[i];
            else
                self[a[i]]=min(c[i],self[a[i]]);
            continue;
        }
        if(!mp[make_pair(a[i],b[i])])
            mp[make_pair(a[i],b[i])]=c[i];
        else
            mp[make_pair(a[i],b[i])]=min(mp[make_pair(a[i],b[i])],c[i]);
    }
    for(auto it:mp){
        pair<int,int> p;
        p=it.first;
        int u=p.first,v=p.second,w=(it.second);
//        cout<<u<<" "<<v<<" "<<w<<endl;
        g[u].pb((node){v,w});
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    for(int i=1;i<=n;i++){
        int ans=inf;
        if(self[i]!=0)
            ans=self[i];
        for(int j=1;j<=n;j++){
            if(i!=j){
                ans=min(ans,dis[i][j]+dis[j][i]);
            }
        }
        if(ans>=inf)
            cout<<"-1";
        else
            cout<<ans;
        cout<<endl;
    }
    return 0;
}
