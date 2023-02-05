#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int out[N],in[N];
int sig;
int color[N];
stack<int> s;
int dfn[N],low[N],used[N],vis[N],cnt,num[N];
void paint(int x){
    s.pop();
    color[x]=sig;
    num[sig]++;
    vis[x]=0;
}
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    s.push(x);
    vis[x]=used[x]=1;
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(!dfn[to]){
            tarjan(to);
            low[x]=min(low[x],low[to]);
        }else if(vis[to]){
            low[x]=min(low[x],dfn[to]);
        }
    }
    if(low[x]==dfn[x]){
        sig++;
        while(s.top()!=x){
            int temp=s.top();
            paint(temp);
        }
        paint(x);
    }
}
signed main(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
    }
    sig=0;
    for(int i=1;i<=n;i++){
        if(!used[i])
            tarjan(i);
    }
    int ans=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(color[i]!=color[v[i][j]]){
                out[color[i]]++;
            }
        }
    }
    for(int i=1;i<=sig;i++){
        if(!out[i]){
            ans+=num[i];
            sum++;
        }
    }
    if(sum==1) cout<<ans;
    else cout<<"0";
    return 0;
}
