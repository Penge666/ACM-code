/*
���������������ٵĴ��۰�Ҷ�ӽڵ㵽���ڵ�ľ��������ͬ

��Ȼ�����ǵ����������ڵ����֦������Ҷ�ӽڵ������ڵ�ľ��붼�����ӣ����ԣ�����Խ�����ڵ����֦�����Ĵ���Խ�١�

Ϊ�˷�����ͼ��Ч��ֱ�ۣ��ڴ������ýڵ������Ⱦ���

�������ǿ������ҵ������Ҷ�ӽڵ�

�ٴ���С��������ʼ���������ӽڵ������ͬһ��ȣ��ٵ��������������֦
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f;
struct Node{int v,w;};
vector<Node> g[N];
int ans,n,s,dp[N];//dp[u]:��uΪ���ڵ������������ĳ���
int dfs(int u,int fa){
    dp[u]=0;//��ʾ�ӵ�ǰ�������ߵ����ĳ���
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        int d=dfs(v,u)+w;
        dp[u]=max(dp[u],d);
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int w=g[u][i].w;
        if(v==fa) continue;
        ans+=(dp[u]-w-dp[v]);
    }
    return dp[u];
}
signed main(){
    cin>>n>>s;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((Node){b,c});
        g[b].push_back((Node){a,c});
    }
    dfs(s,0);
    cout<<ans;
    return 0;
}
/*
5 2
1 2 1
1 3 3
2 4 4
2 5 2
*/
