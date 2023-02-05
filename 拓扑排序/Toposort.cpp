#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
const int mod = 1e9+7;
vector<int> v[N];
int in[N];
priority_queue<int,vector<int>,greater<int> > q;
map<int,int> vis;
int inq[N];
int n,m,k;
void init(){
    while(!q.empty()) q.pop();
    for(int i=0;i<=n;i++){
        in[i]=0;
        v[i].clear();
        inq[i]=0;
    }
    vis.clear();
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%lld%lld",&a,&b);
            in[b]++;
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(in[i]<=k){
                q.push(i);
                inq[i]=1;
            }
        }
        int ans=0;
        int cnt=1;
        while(!q.empty()){
            int t=q.top();
            q.pop();
            inq[t]=0;
            if(in[t]<=k){
                k-=in[t];
                ans=(ans+1ll*t*cnt)%mod;
                vis[t]=1;
                cnt++;
                for(int i=0;i<v[t].size();i++){
                    int to=v[t][i];
                    if(vis[to]) continue;
                    in[to]--;
                    if(!inq[to]&&in[to]<=k){
                        q.push(to);
                        inq[to]=1;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
