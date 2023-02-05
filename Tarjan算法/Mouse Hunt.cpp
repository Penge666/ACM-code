/*

�������Ǹ���n��λ�÷Ų������ļ�ֵ��Ȼ�����n�����֣������ i �ܹ��ߵ�����㡣�����ټ�ֵ�Ų�����ʹ������ȫ��ץ����

˼·���޷Ǿ����л����޻�����������л���ʱ�򻹲�Ҫ���ǿ��ǡ�������������û�ж�������ȥ�Ļ�����������ͼ����Ĵ���������ע�͵ú���ϸ��

�л��Ļ�һ�����ڻ��ϲ��Ҹõ㻨����С��

�޻��Ļ����Ƿ�������Ǹ������

�������˵Ļ���Ҫ��ȥ��һȦ��

����ܺã�������������


*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 999999999999
#define N 666666
int c[N];
vector<int> v[N];
int sig;
int dfn[N],low[N],cnt;
int num[N],color[N];
int vis[N],used[N];
stack<int> s;
int MIN[N];
int IN[N],OUT[N];
void paint(int x){
    s.pop();
    vis[x]=0;
    num[sig]++;
    MIN[sig]=min(MIN[sig],c[x]);
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
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        v[i].push_back(temp);
    }
    for(int i=1;i<=n;i++) MIN[i]=inf;
    sig=0;
    for(int i=1;i<=n;i++){
        if(!used[i])
            tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(color[i]!=color[v[i][j]]){
                OUT[color[i]]++;
                IN[color[v[i][j]]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=sig;i++){
        if(!OUT[i])
            ans+=MIN[i];
    }
    printf("%lld",ans);
    return 0;
}
