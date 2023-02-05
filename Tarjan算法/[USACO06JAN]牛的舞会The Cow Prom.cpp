/*
给定一个图，要求图中节点数大于一的强联通分量个数。


1，DFN［］作为这个点搜索的次序编号（时间戳），简单来说就是 第几个被搜索到的。％每个点的时间戳都不一样％。

2，LOW［］作为每个点在这颗树中的，最小的子树的根，每次保证最小，like它的父亲结点的时间戳这种感觉。如果它自己的LOW［］最小，那这个点就应该从新分配，变成这个强连通分量子树的根节点。
参考：https://blog.csdn.net/csyifanZhang/article/details/105370924
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int low[N],dfn[N],cnt;
int num[N];
int sig;
int vis[N],used[N];
stack<int> s;
int color[N];

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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    sig=0;
    for(int i=1;i<=n;i++){
        if(!used[i]) tarjan(i);
    }
    int ans=0;
//    cout<<sig<<'\n';
    for(int i=1;i<=sig;i++){
//        cout<<num[i]<<" ";
        if(num[i]>1) ans++;
    }
    //cout<<'\n';
    cout<<ans;
    return 0;
}
