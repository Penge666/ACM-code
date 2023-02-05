/*
��Ŀ���� �� ����һ������ͼ�� ������m�� ��ʾ ����Ժ�m������ϵ�� ����������Ҫ��ϵ���ٸ��ˣ� ������ϵ�������ˣ�

˼· ��  ���ѿ�������һ��ǿ��ͨ�⣬�����Ĺؼ��������ܹ���ϵ�����ǲ��ǰ�����������Ҫ����ϵ���ˣ� ������ǵĻ��� ��ô���޷���ϵ�����ˣ� ֱ����� -1�ͺá� ��ô��Ҫ����ϵ���˾���ʲô�ص��أ�д��һ���ˮ���������tarjan��һ��Ӧ�����������Ⱥͳ��ȵ����⣬ ��������Ҳ�����й� ��

 

������ͼΪ���� ������ܹ�֪ͨ����ֻ��1����2�� ��ô���޷�֪ͨ���������ˣ������1 �� 2 ����֪ͨ�� ��ô����֪ͨ����������2�����ѿ����� ��������Ϊ0�ĵ㶼����Ҫ��֪ͨ�ĵ㣬 ���ǵ��ܺ;���������Ҫ֪ͨ�������ˣ� ��Ϊ��Ȳ�Ϊ0�ĵ㶼����������֪ͨ����㻹�ǱȽ�����ġ�

�����������֪ͨ���˵Ĵ洢��ʽ�� ������ѡ�����map�� �������֪ͨ���˵�second�� + 1�� Ϊ0 �Ķ��ǲ���֪ͨ�ģ������������Ϊ0�ĵ��ʱ�� ����õ��second��ֵ��Ϊ�յĻ��� sum ++�� ����ֱ�����-1 �ͺá�

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define  N 666666
int n,m;
int arr[N];
int low[N],dfn[N],cnt;
int vis[N],used[N];
int f[N];
int num[N],color[N];
vector<int> v[N];
int sig;
int mark[N];
stack<int> s;
int IN[N],OUT[N];
map<int,int> mp;
int MIN[N];


void paint(int x){
    s.pop();
    vis[x]=0;
    num[sig]++;
    color[x]=sig;
    MIN[sig]=min(MIN[sig],x);
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
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>arr[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(t--){
            int u;
            cin>>u;
            v[i].push_back(u);
        }
    }
    sig=0;
    for(int i=1;i<=n;i++)
        if(!used[i])
            tarjan(i);

    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(color[i]!=color[v[i][j]]){
                IN[color[v[i][j]]]++;
                OUT[color[i]]++;
            }
        }
    }
//    cout<<sig;
    int sum=0;
    for(int i=1;i<=sig;i++){
        if(!IN[i]){
            int f=0;
            for(int j=1;j<=m;j++){
                if(color[arr[j]]==i){
                    f=1;
                    break;
                }
            }
            if(!f){
                printf("-1\n");
                return 0;
            }
            sum++;
        }

    }

    cout<<sum;
    return 0;
}
