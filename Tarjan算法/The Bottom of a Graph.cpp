/*
题意：在有向图G中，给这样一个新的定义：对于在G中任何一个点v可达的点w，w都可达v，那么点v是一个sink。G图的bottom子图是由G图中所有的sink点构成，请按照顺序输出G图对应的bottom子图中的所有点编号，如果没有sink点，那么输出一个空行。
 
题目分析：先将题目的强联通分量求出来缩成点，然后判断连通分量出度为0点 分量。

*/
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
signed main(){
    while(~scanf("%lld",&n)&&n){
        init();
        scanf("%lld",&m);
        while(m--){
            int a,b;
            scanf("%lld%lld",&a,&b);
            v[a].push_back(b);
        }
        sig=0;
        for(int i=1;i<=n;i++){
            if(!used[i]) tarjan(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                if(color[i]!=color[v[i][j]]){
                    out[color[i]]++;
                }
            }
        }
        for(int i=1;i<=sig;i++){
            if(!out[i]){
                MP[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(MP[color[i]]){
                printf("%lld ",i);
            }
        }
        printf("\n");
    }
    return 0;
}
