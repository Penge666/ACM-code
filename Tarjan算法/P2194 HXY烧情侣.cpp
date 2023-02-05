#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 266666
#define inf 9999999999
int arr[N];
int sig;
int n,m;
vector<int> v[N];
int dfn[N],low[N],cnt;
int vis[N],used[N];
int color[N],num[N];
int in[N],out[N];
stack<int> s;
map<int,int> MP;
void init(){
    sig=0;cnt=0;
    for(int i=0;i<=n;i++){
        v[i].clear();
        dfn[i]=0;
        low[i]=0;
        vis[i]=0;
        used[i]=0;
        color[i]=0;
        num[i]=0;
        out[i]=0;
    }
    MP.clear();
    while(!s.empty()) s.pop();
}
void paint(int x){
    s.pop();
    vis[x]=0;
    num[sig]++;
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
            int temp=s.top();
            paint(temp);
        }
        paint(x);
    }
}
struct str{
    int sum=inf;
    map<int,int> mp;
}st[N];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    scanf("%lld",&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
    }
    sig=0;
    for(int i=1;i<=n;i++){
        if(!used[i]) tarjan(i);
    }
     int res1=0,res2=1;
     //cout<<sig;
     for(int i=1;i<=n;i++){
         st[color[i]].sum=min(st[color[i]].sum,arr[i]);
         st[color[i]].mp[arr[i]]++;
    }
    for(int i=1;i<=sig;i++){
        res1+=st[i].sum;
        res2*=st[i].mp[st[i].sum];
    }
    cout<<res1<<" "<<res2;
    return 0;
}
