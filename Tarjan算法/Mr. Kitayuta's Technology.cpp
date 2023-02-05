// ���⣺��һ������ͼ�У���n�����㣬����m�����֣�u,v����ʾ����u�Ͷ���v����ֱ�ӻ��߼�����������㹹��һ��������ͼ�����������Ҫ�������ߡ�
//
//˼·��һ������ͨ����û�л��Ļ���ô�Դ𰸵Ĺ��׾��Ǹ���ͨ���е���-1
//
//����Ϊ��ĸ���
//
//�������ò��鼯ά��һ�¼���
//
//https://codeforces.com/contest/505/problem/D

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N];
int low[N],dfn[N],cnt;
int vis[N],used[N];
int f[N];
int num[N],color[N];
vector<int> v[N];
int sig;
int mark[N];
stack<int> s;
void paint(int x){
    s.pop();
    vis[x]=0;
    num[sig]++;
    if(num[sig]>1)
        mark[sig]=1;
    color[x]=sig;
}
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    vis[x]=used[x]=1;
    s.push(x);
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(!dfn[to]){
            tarjan(to);
            low[x]=min(low[x],low[to]);
        }else if(vis[to]){
            low[x]=min(low[x],dfn[to]);
        }
    }
    if(dfn[x]==low[x]){
        sig++;
        while(s.top()!=x){
            int t=s.top();
            paint(t);
        }
        paint(x);
    }
}
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
void merge (int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        f[max(t1,t2)]=min(t1,t2);
        num[min(t1,t2)]+=num[max(t1,t2)];
        mark[min(t1,t2)]|=mark[max(t1,t2)];
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
    for(int i=1;i<=n;i++)
        if(!used[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int t1=color[i];
            int t2=color[v[i][j]];
            merge(t1,t2);
        }
    }
    int ans=0;
    for(int i=1;i<=sig;i++){
        if(f[i]==i){
            if(mark[i]) ans+=num[i];
            else ans+=num[i]-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
