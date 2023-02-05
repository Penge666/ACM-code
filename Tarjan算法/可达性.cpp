//思路：缩短之后找度为0的点中最小的那个点
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999999999
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++) MIN[i]=inf;
    sig=0;
    for(int i=1;i<=n;i++)
        if(!used[i])
            tarjan(i);
    if(sig==1){
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int t1=color[i];
            int t2=color[v[i][j]];
            if(t1!=t2){
                IN[t1]++;OUT[t2]++;
            }

        }
    }
    vector<int> ans;
    for(int i=1;i<=sig;i++){
        if(!OUT[i]) {
            ans.push_back(MIN[i]);
        }
                //mp[i]=1;
        //    ans.push_back(i);
    }

    printf("%lld\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        if(i) printf(" %lld",ans[i]);
        else printf("%lld",ans[i]);
    }
    return 0;
}
