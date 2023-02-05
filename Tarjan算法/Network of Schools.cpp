//��n(2<=n<=100)��ѧУ��ѧУ֮���е������磬һ��ѧУ�ڵõ����֮�����˳�ŵ�������������ѧУ����
//�������ÿ��ѧУ����������ѧУ����Ĵ����б�
//1.��ʼʱ���ټ���ѧУ�õ����������ʹ������������ѧУ���յ������
//2.������Ӽ����ߣ�����ʹ��������������һ��ѧУ���͸�����������ܴ���������ÿһ��ѧУ
//
//˼·��
//
//˼·������д��ǰ��ģ�������Ѿ���һ��ǿ��ͨͼ�Ļ�����ô���ǾͲ���Ҫ�ټӱ��ˣ���Ҫ���С����ߣ�������Ҫ����������Ϣ���������ʵ�������֮�����Ϊ0�ĵ�ĸ�������Ҫ����Ӽ����ߣ����ǿ������Ϊ0�ͳ���Ϊ0�ĵ�ĸ��������ֵ�����Ƕ�Ӧ���߼��ɡ�
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
#define int long long
#define N 666666
int n;
int sig;
vector<int> v[N];
int low[N],dfn[N],cnt;
int vis[N],used[N];
int num[N],color[N];
int in[N],out[N];
stack<int> s;
void init(){
    sig=0;cnt=0;
    for(int i=0;i<=n;i++){
        v[i].clear();
        low[i]=0;
        dfn[i]=0;
        vis[i]=0;
        used[i]=0;
        num[i]=0;
        color[i]=0;
    }
    while(!s.empty()) s.pop();
}

void paint(int x){
    s.pop();
    color[x]=sig;
    num[sig]++;
    vis[x]=0;
}
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    s.push(x);
    vis[x]=used[x]=1;
    for(int i=0;i<v[x].size();i++){
        int to=v[x][i];
        if(!dfn[to]){
            tarjan(to);
            low[x]=min(low[x],low[to]);
        }else if(vis[to]){
            low[x]=min(low[x],dfn[to]);
        }
    }
    if(low[x]==dfn[x]){
        sig++;
        while(s.top()!=x){
            int temp=s.top();
            paint(temp);
        }
        paint(x);
    }
}

signed main(){
    while(~scanf("%lld",&n)&&n){
        init();
        for(int i=1;i<=n;i++){
            int m;
            while(~scanf("%lld",&m)&&m){
                v[i].push_back(m);
            }
        }
        for(int i=1;i<=n;i++){
            if(!used[i]) tarjan(i);
        }
        if(sig==1){
            printf("1\n0\n");
            continue;
        }
        int ans1=0;
        int ans2=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                if(color[i]!=color[v[i][j]]){
                    in[color[v[i][j]]]++;
                    out[color[i]]++;
                }
            }
        }
        for(int i=1;i<=sig;i++){
            if(!out[i]) ans1++;
            if(!in[i])  ans2++;
        }
        printf("%lld\n%lld\n",ans2,max(ans1,ans2));
    }
    return 0;
}
