/*
��һ�β�������������ģ�������
��������Ŀ��û�һ�����Ƚ����������

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 0x3f3f3f3f;
int n,a[N],sum;
vector<int> g[N];
int dep[N];
int val[N];//��uΪ���ڵ�����������нڵ�Ȩֵ
int dp[N]; //��uΪ���ڵ������������Ŀ��ʽ��ֵ
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    val[u]=a[u];
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dfs1(to,u);
        val[u]+=val[to];
    }
}
void dfs2(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i];
        if(to==fa) continue;
        dp[to]=dp[u]-val[to]+(sum-val[to]);
        dfs2(to,u);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dep[0]=-1;
    dfs1(1,0);//��߶�
    for(int i=1;i<=n;i++) dp[1]+=dep[i]*a[i];
    dfs2(1,0);
    int ans=-inf;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
