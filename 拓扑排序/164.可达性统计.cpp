//由于是有向无环图，所以最长路肯定是一个入度为0到出度为0的路径，拓扑序在确定当前点之前能够考虑到所有到它的情况，所以最后取个最值即可。

#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m;
#define N 666666
vector<pair<int,int> > v[N];
int in[N],out[N],dis[N];
map<int,int> vis;
void init(){
    vis.clear();
    for(int i=0;i<=n;i++){
        v[i].clear();dis[i]=0;
        in[i]=0;out[i]=0;
    }
}
signed main(){
    int T;cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            in[b]++;out[a]++;
            v[a].push_back(make_pair(b,c));
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!in[i]){
                vis[i]=1;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<v[u].size();i++){
                int to=v[u][i].first;
                in[to]--;
                dis[to]=max(dis[to],dis[u]+v[u][i].second);
                if(!in[to]){
                    q.push(to);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!out[i]) ans=max(ans,dis[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
