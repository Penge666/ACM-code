#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 9999999999999999
#define N 266666
int n,m;
vector<pair<int,int> > v1[N],v2[N];
map<int,int> vis;
int dis1[N],dis2[N];
struct node{
    int now;
    int w;
    bool operator < (const node &r) const {
        return w>r.w;
    }
};
struct str{
    int x,y,z;
}st[N];

void dij1(int st){
    for(int i=0;i<=n+10;i++) dis1[i]=inf;
    dis1[st]=0;vis.clear();
    priority_queue<node> q;
    q.push((node){st,0});
    while(!q.empty()){
        struct node t=q.top();
        q.pop();
        if(vis[t.now]) continue;
        vis[t.now]=1;
        for(int i=0;i<v1[t.now].size();i++){
            if(dis1[v1[t.now][i].first]>dis1[t.now]+v1[t.now][i].second){
                dis1[v1[t.now][i].first]=dis1[t.now]+v1[t.now][i].second;
                q.push((node){v1[t.now][i].first,dis1[v1[t.now][i].first]});
            }
        }
    }
}
void dij2(int st){
    for(int i=0;i<=n+10;i++) dis2[i]=inf;
    dis2[st]=0;vis.clear();
    priority_queue<node> q;
    q.push((node){st,0});
    while(!q.empty()){
        struct node t=q.top();
        q.pop();
        if(vis[t.now]) continue;
        vis[t.now]=1;
        for(int i=0;i<v2[t.now].size();i++){
            if(dis2[v2[t.now][i].first]>dis2[t.now]+v2[t.now][i].second){
                dis2[v2[t.now][i].first]=dis2[t.now]+v2[t.now][i].second;
                q.push((node){v2[t.now][i].first,dis2[v2[t.now][i].first]});
            }
        }
    }
}
signed main(){

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        st[i].x=a;st[i].y=b;st[i].z=c;
        v1[a].push_back(make_pair(b,c));
        v2[b].push_back(make_pair(a,c));
    }
    dij1(1);
    dij2(n);
    int Q;
    cin>>Q;
    while(Q--){
        int num;
        scanf("%lld",&num);
        if(dis1[n]>dis1[st[num].y]+dis2[st[num].x]+st[num].z) cout<<"YES"<<'\n';else cout<<"NO"<<'\n';
    }
    return 0;
}
