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
vector<int> v[N];

map<int,int> mp;

int dfn[N],low[N],cnt;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++cnt;
    int child=0;
    for(int i=0;i<v[u].size();i++){
        int to=v[u][i];
        if(!dfn[to]){
            tarjan(to,u);
            low[u]=min(low[u],low[to]);
            if(low[to]>=dfn[u]&&u!=fa){
                mp[u]=1;
            }
            if(u==fa) child++;
        }
        low[u]=min(low[u],dfn[to]);
    }
    if(child>=2&&u==fa) mp[u]=1;
}
int n;
void init(){
    mp.clear();
    for(int i=0;i<=n;i++){
        v[i].clear();
        dfn[i]=0;
        low[i]=0;
    }
    cnt=0;
}
signed main(){
    while(~scanf("%lld", &n) && n){
        init();
        int num = 0;
        while(~scanf("%lld", &num) && num){
            int x;
            while(scanf("%lld", &x)){
                v[x].push_back(num);
                v[num].push_back(x);
                //add(x, num);
                char ch = getchar();
                if(ch == '\n')
                    break;
            }
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]) tarjan(i,i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(mp[i]) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
