/*
题目大意 ： 输入一个有向图， 并给出m， 表示 你可以和m个人联系， 问你最少需要联系多少个人， 才能联系上所有人？

思路 ：  不难看出这是一个强连通题，这道题的关键在于你能够联系的人是不是包含了所有需要被联系的人， 如果不是的话， 那么就无法联系所有人， 直接输出 -1就好。 那么需要被联系的人具有什么特点呢？写了一大堆水题的我碰到tarjan第一反应就是缩点后入度和出度的问题， 碰巧这题也和这有关 ：

 

以这张图为例， 如果你能够通知的人只有1或者2， 那么就无法通知到所有人了，如果你1 、 2 都能通知， 那么最少通知的人数就是2。不难看出， 缩点后入度为0的点都是需要被通知的点， 他们的总和就是你至少要通知的人数了， 因为入度不为0的点都由其他人来通知，这点还是比较清楚的。

最后就是你可以通知的人的存储方式， 这里我选择的是map， 把你可以通知的人的second都 + 1， 为0 的都是不可通知的，在最后遍历入度为0的点的时候， 如果该点的second的值不为空的话， sum ++， 否则直接输出-1 就好。

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
