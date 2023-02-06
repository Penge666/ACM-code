#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 3666666
#define inf 999999999999
map<pair<int,int>,int> mp;
vector<pair<int,int> >v[N];
struct str{
    int now,w;
    bool operator < (const str &t) const {
        return w>t.w;
    }
};
int n,m,cnt;
int vis[N],dis[N];
void dij(int st){
    for(int i=0;i<=cnt+10;i++) dis[i]=inf,vis[i]=0;
    dis[st]=0;
    priority_queue<str> q;
    q.push((str){st,0});
    while(!q.empty()){
        struct str t=q.top();
        q.pop();
        if(vis[t.now]) continue;
        vis[t.now]=1;
        for(int i=0;i<v[t.now].size();i++){
            if(dis[v[t.now][i].first]>dis[t.now]+v[t.now][i].second){
                dis[v[t.now][i].first]=dis[t.now]+v[t.now][i].second;
                q.push((str){v[t.now][i].first,dis[v[t.now][i].first]});
            }
        }
    }
}
signed main(){

    scanf("%lld%lld",&n,&m);
    cnt=n+1;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int t1=0,t2=0;
        if(!mp[make_pair(a,c)])
             mp[make_pair(a,c)]=cnt++;

        if(!mp[make_pair(b,c)])
            mp[make_pair(b,c)]=cnt++;

        t1=mp[make_pair(a,c)];
        t2=mp[make_pair(b,c)];
        v[t1].push_back(make_pair(t2,0));
        v[t2].push_back(make_pair(t1,0));
        v[a].push_back(make_pair(t1,1));
        v[t1].push_back(make_pair(a,1));
        v[b].push_back(make_pair(t2,1));
        v[t2].push_back(make_pair(b,1));
    }
    dij(1);
    if(dis[n]==inf) cout<<"-1";
    else cout<<dis[n]/2;
    return 0;
}
