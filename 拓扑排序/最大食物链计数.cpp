#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
#define mod 80112002
int arr[N];
int dis[N];
int in[N],out[N];
vector<int> v[N];
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            dis[i]=1;
        }
    }
    int ans=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int to=v[u][i];
            in[to]--;
            dis[to]=(dis[u]+dis[to])%mod;
            if(in[to]==0){
                q.push(to);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!out[i]){
            cout<<dis[i]<<" ";
            ans+=dis[i],ans%=mod;
        }
    }
    cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}

/*
6 6
1 2
1 3
2 4
3 4
5 3
2 6
*/
