/*
��Ϊ����һ������������xΪ�����������ڵ�x���ܲ����Ĺ���Ϊsize(x)��������ɵ�һ������
�ܹ��ױ�Ϊÿ����Ĺ���֮�͡�
������λ�������Ȼ����ÿһ���ڵ㶼���Գ�Ϊ���ڵ㣬������dfsһ���ҳ�һ�����Ĺ��ף���
����ڵ�Ϊ1����Ȼ�������1�����ӵ����е����ת�ơ���f[x]��ʾ��xΪ���ڵ��������Ĵ�
�ۣ������x�����ӵ�ÿ����y����f[y]=f[x]-size(y)+n-size(y) �����Ҫ��ͼ���һ�¡�
����Ϊ����һ�λ�����x��y����ĵ�û�ж�֮ǰ�Ĵ𰸲����µ�Ӱ�죬ֻ��Ҫ����x��y������
��������׵ı仯ֵ���ɡ�
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f ;
vector<int> g[N];
int dp[N];//dp[u]:��һ����Ϳ�ڵ�u����õ�����ֵ
int n,sz[N],num[N];//num[u]:�ڵ�u����ͨ���С
void dfs1(int u,int fa){
    sz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dfs1(to,u);
        sz[u]+=sz[to];
    }
}
void dfs2(int u,int fa){
    num[u]=1;
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        num[u]+=sz[to];
        dfs2(to,u);
    }
}
void dfs3(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dp[to]=dp[u]-(num[to]-(n-num[to]));
        dfs3(to,u);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);

    for(int i=1;i<=n;i++) dp[1]+=num[i];
    dfs3(1,0);
    int ans=-inf;
    /*
    for(int i=1;i<=n;i++) cout<<num[i]<<" ";
    cout<<'\n';
    */
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

    cout<<ans;
    return 0;
}
