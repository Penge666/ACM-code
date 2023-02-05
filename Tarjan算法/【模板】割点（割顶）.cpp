/*��㶨�壺

���
����ɾ��һ����,Ҫʹԭ����ͨ������(������)�Ľڵ㲻��ͨ

/*

����tarjan������ص����dfn��low�������⡣

dfn[i]����ʱ���,����ʲôʱ���������˵�i,

low[i]����i���ܻ��ݵ���dfn��С������,

������ʱ���ж�һ�µ����ڵ�x���ڶ��ӽڵ�y,ʹ��dfn[x]<=low[y]��xһ���Ǹ�㡣

��ΪֻҪx���ӽڵ㲻�ܻ��ݵ�x�����棬����û�з���߳���x�㣬��ô���x������ɲ���ͨ��

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
