#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int n,m;
string name[N];
struct node{
    int id;
};
bool operator < (node a,node b){
    return name[a.id]>name[b.id];
}
priority_queue<node> q;
unordered_map<string,int> mp;
int in[N];
vector<int> v[N];
vector<string> ans;
void init(){
    while(!q.empty()) q.pop();
    for(int i=0;i<=n+1;i++) v[i].clear(),in[i]=0;
    ans.clear();
    mp.clear();
}
void toposort(){
    int sum=0;
    while(!q.empty()){
        struct node temp=q.top();
        int  u=temp.id;
        q.pop();
        sum++;
        ans.push_back(name[u]);
        for(int i=0;i<v[u].size();i++){
            int to=v[u][i];
            in[to]--;
            if(!in[to])     q.push((node){to});
        }
    }
    if(sum==n){
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<'\n';
    }else{
        printf("Impossible\n");
    }


}
signed main(){

    int cnt=1;
    int T;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        init();
        for(int i=1;i<=n;i++){
            cin>>name[i];
            mp[name[i]]=i;
        }
        for(int i=1;i<=m;i++){
            string x,y;
            cin>>x>>y;
            v[mp[x]].push_back(mp[y]);
            in[mp[y]]++;
        }
        for(int i=1;i<=n;i++){
            if(!in[mp[name[i]]]){
                q.push((node){mp[name[i]]});
            }
        }
        printf("Case #%lld:\n",cnt++);
        toposort();
    }
    return 0;
}
