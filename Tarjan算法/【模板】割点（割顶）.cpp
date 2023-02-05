/*割点定义：

割点
我们删除一个点,要使原本互通的两个(或以上)的节点不互通

/*

首先tarjan求割点的重点就是dfn和low数组的理解。

dfn[i]就是时间戳,即在什么时刻搜索到了点i,

low[i]则是i点能回溯到的dfn最小的祖先,

搜索的时候判断一下当对于点x存在儿子节点y,使得dfn[x]<=low[y]则x一定是割点。

因为只要x的子节点不能回溯到x的上面，就是没有返祖边超过x点，那么割掉x就能造成不连通了

*/

#include<bits/stdc++.h>
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
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i,i);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(mp[i]) sum++;
    }
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++)
        if(mp[i])
            printf("%lld ",i);
    return 0;
}
