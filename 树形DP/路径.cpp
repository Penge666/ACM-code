/*
考虑树形dp,dp[i][0/1]分别表示从子树中到i结点的偶数路径和奇数路径有多少,那么有如下转移:
dp[i][0] += dp[u][1]
dp[i][1] += dp[u][0]。
对于统计答案我们可以暴力计算

*/

/*
dp[u][0/1]:以u为根节点的子树中,长度为[奇数/偶数]的最大值
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 ,inf = 0x3f3f3f3f ;
struct Node{int v,w;};
int n;
vector<Node> g[N];
int ans;
int dp[N][6];
void dfs(int u,int fa){
    dp[u][0]=-inf,dp[u][1]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0]=max(dp[u][0],dp[v][1]+w);
        dp[u][1]=max(dp[u][1],dp[v][0]+w);
    }
    for(int i=0;i<g[u].size();i++){
        for(int j=0;j<g[u].size();j++){
            if(i!=j){
                int t1=g[u][i].v,t2=g[u][j].v;
                int s=g[u][i].w+g[u][j].w;
                ans=max(ans,max(dp[t1][1]+dp[t2][1]+s,dp[t1][0]+dp[t2][0]+s));
            }
        }
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
    dfs(1,-1);
    cout<<ans;
    return 0;
}
