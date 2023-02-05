#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
#define int long long
#define N 666666
int sig;
int n,m;
vector<int> v[N];
int dfn[N],low[N],cnt;
int vis[N],used[N];
int color[N],num[N];
int in[N],out[N];
stack<int> s;

void init(){
    sig=0;cnt=0;
    for(int i=0;i<=n;i++){
        v[i].clear();
        dfn[i]=0;
        low[i]=0;
        vis[i]=0;
        used[i]=0;
        color[i]=0;
        num[i]=0;
        out[i]=0;
    }
    while(!s.empty()) s.pop();
}
void paint(int x){
    s.pop();
    vis[x]=0;
    num[sig]++;
    color[x]=sig;
}
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    vis[x]=used[x]=1;
    s.push(x);
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(!dfn[to]){
            tarjan(to);
            low[x]=min(low[x],low[to]);
        }else if(vis[to]){
            low[x]=min(low[x],dfn[to]);
        }
    }
    if(dfn[x]==low[x]){
        sig++;
        while(s.top()!=x){
            int temp=s.top();
            paint(temp);
        }
        paint(x);
    }
}
int aa[N];
vector<int> G[N];
int dp[N];
void dfs(int u){
    if(dp[u]) return ;
    dp[u]=num[u];
    for(int i=0;i<G[u].size();i++){
        int to=G[u][i];
        dfs(to);
        dp[u]+=dp[to];
    }
//return dp[u];
}
signed main(){
    scanf("%lld",&n);
    init();
    for(int i=1;i<=n;i++){

        scanf("%lld",&aa[i]);
        v[i].push_back(aa[i]);
    }
    sig=0;
    for(int i=1;i<=n;i++){
        if(!used[i])
            tarjan(i);
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";//颜色的个数
    }
    */
    for(int i=1;i<=n;i++){
        if(color[i]!=color[aa[i]])
             G[color[i]].push_back(color[aa[i]]);
    }
    for(int i=1;i<=n;i++){
        dfs(color[i]);
    }
    for(int i=1;i<=n;i++) cout<<dp[color[i]]<<'\n';
    return 0;
}
