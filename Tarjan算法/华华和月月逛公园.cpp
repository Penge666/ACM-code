#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int ans;
int low[N],dfn[N],cnt;
void tarjan(int x,int fa){
    low[x]=dfn[x]=++cnt;
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(!dfn[to]){
            tarjan(to,x);
            low[x]=min(low[x],low[to]);
            if(low[to]>dfn[x]) ans++;
        }else if(to!=fa){
            low[x]=min(low[x],dfn[to]);
        }
    }
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
    tarjan(1,0);
    cout<<m-ans;
    return 0;
}
