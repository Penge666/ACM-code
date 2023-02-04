//处理出每个点到根的异或值，询问两个点即为这两个点到根的异或值异或一下即可


#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1666666 , inf = 0x3f3f3f3f;
int n,q;
struct Node{int v,w;};
vector<Node> g[N];
int dis[N];
void dfs(int u,int fa,int wi){
    dis[u]=dis[fa]^wi;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        dfs(v,u,w);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    dfs(1,0,0);
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<(dis[u]^dis[v])<<'\n';
    }
    return 0;
}
