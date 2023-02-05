#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 266666
#define inf 9999999999
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
    int x,y;
}st[N];
map<int,int> Vis;
map<string,int> mp;

signed main(){
    scanf("%lld",&n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        string sa,sb;
        cin>>sa>>sb;
        if(!mp[sa]) mp[sa]=++cnt;
        if(!mp[sb]) mp[sb]=++cnt;
        v[mp[sa]].push_back(mp[sb]);
        st[i].x=mp[sa];
        st[i].y=mp[sb];
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        v[mp[b]].push_back(mp[a]);
    }
    sig=0;
    for(int i=1;i<=2*n;i++){
        if(!used[i]) tarjan(i);
    }

    for(int i=1;i<=n;i++){
        if(color[st[i].x]==color[st[i].y]){
            cout<<"Unsafe"<<'\n';
        }else{
            cout<<"Safe"<<'\n';
        }
    }
    return 0;
}
