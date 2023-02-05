//有n(2<=n<=100)个学校，学校之间有单向网络，一个学校在得到软件之后可以顺着单向网络向其他学校传输
//输入给出每个学校可以向其他学校传输的传输列表
//1.初始时至少几个学校得到该软件才能使得网络内所有学校都收到该软件
//2.至少添加几条边，才能使得向网络中任意一个学校发送该软件，最终能传遍网络中每一个学校
//
//思路：
//
//思路：首先写在前面的，如果它已经是一幅强连通图的话，那么我们就不需要再加边了，需要特判。再者，考虑需要给出几个消息，不就是问的是缩点之后入度为0的点的个数吗；需要再添加几条边，就是考虑入度为0和出度为0的点的个数的最大值，我们对应连边即可。
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
