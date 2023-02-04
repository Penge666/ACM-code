#include<bits/stdc++.h>

using namespace std;
const int N = 10010 , M = 20020;
int n,ans;
struct Node{
    int v,w;
};
vector<Node> g[N];
int dfs(int u,int fa){
    int dist=0;//表示从当前点往下走的最大长度
    int d1=0,d2=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        int d=dfs(v,u)+w;
        dist=max(dist,d);
        if(d>=d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(d1+d2,ans);
    return dist;
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    dfs(1,-1);
    cout<<ans;
    return 0;
}
