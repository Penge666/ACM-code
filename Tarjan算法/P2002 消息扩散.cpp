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
map<int,int> MP;
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
    MP.clear();
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
vector<int> e[N];

signed main(){
        cin>>n>>m;
        init();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%lld%lld",&a,&b);
            if(a!=b)
                v[a].push_back(b);
        }
        sig=0;
        for(int i=1;i<=n;i++){
            if(!used[i])
                tarjan(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                if(color[i]!=color[v[i][j]]){
                    in[color[v[i][j]]]++;
                }
            }
        }
        int ans=0;
        //cout<<sig<<'\n';
        for(int i=1;i<=sig;i++){
            if(!in[i]){
                ans++;
            }
        }

        printf("%lld\n",ans);

    return 0;
}
